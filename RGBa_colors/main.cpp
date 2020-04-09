#include <iostream>
#include <SFML/Graphics.hpp>

#define window_width 1280
#define window_height 720

sf::Image load();

void loop();

int main()
{
	loop();
	return 0;
}

sf::Image load()
{
	sf::Image image;
	std::string path;

	do
	{
		std::cout << "Path : ";
		std::cin >> path;
	} while (!image.loadFromFile(path));

	return image;
}

void loop()
{
	//Load
	sf::Image origin = load(); // original picture
	sf::Image r, g, b, a;     // red, green, blue, alfa - Form

	//worging
	r.create(origin.getSize().x, origin.getSize().y); //
	g.create(origin.getSize().x, origin.getSize().y); // Set size picture
	b.create(origin.getSize().x, origin.getSize().y); //
	a.create(origin.getSize().x, origin.getSize().y); //

	sf::Color buff;

		// set pixels
	for (size_t y = 0; y < origin.getSize().y; y++)
	{
		for (size_t x = 0; x < origin.getSize().x; x++)
		{
			buff = origin.getPixel(x, y);

			r.setPixel(x, y, sf::Color(buff.r, 0, 0));
			g.setPixel(x, y, sf::Color(0, buff.g, 0));
			b.setPixel(x, y, sf::Color(0, 0, buff.b));
			a.setPixel(x, y, sf::Color(255, 255, 255, buff.a));
		}
	}

	//View
	sf::RenderWindow window(sf::VideoMode(window_width, window_height), "RGBa"); // create window
	window.setFramerateLimit(10); // FPS

		// create and set position - rectangle
	sf::RectangleShape origin_rec(sf::Vector2f(window_width / 2, window_height));
	origin_rec.setPosition(0,0);
	sf::RectangleShape r_rec(sf::Vector2f(window_width / 4, window_height / 2));
	r_rec.setPosition(window_width / 2, 0);
	sf::RectangleShape g_rec(sf::Vector2f(window_width / 4, window_height / 2));
	g_rec.setPosition(window_width * 0.75, 0);
	sf::RectangleShape b_rec(sf::Vector2f(window_width / 4, window_height / 2));
	b_rec.setPosition(window_width / 2, window_height / 2);
	sf::RectangleShape a_rec(sf::Vector2f(window_width / 4, window_height / 2));
	a_rec.setPosition(window_width * 0.75, window_height / 2);

		// set texture on rectangle
	sf::Texture origin_tex;
	origin_tex.loadFromImage(origin);
	origin_rec.setTexture(&origin_tex);

	sf::Texture r_tex;
	r_tex.loadFromImage(r);
	r_rec.setTexture(&r_tex);

	sf::Texture g_tex;
	g_tex.loadFromImage(g);
	g_rec.setTexture(&g_tex);

	sf::Texture b_tex;
	b_tex.loadFromImage(b);
	b_rec.setTexture(&b_tex);

	sf::Texture a_tex;
	a_tex.loadFromImage(a);
	a_rec.setTexture(&a_tex);


	// run the program as long as the window is open
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}

		
		window.draw(origin_rec); // set to render
		window.draw(r_rec);
		window.draw(g_rec);
		window.draw(b_rec);
		window.draw(a_rec);

		window.display(); // render
		window.clear(sf::Color::Black);
	}
}