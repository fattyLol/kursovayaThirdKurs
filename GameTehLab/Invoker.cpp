#include "Invoker.h"

void Invoker::OpenApp()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1280, 720), "Code/Decode text");
}

void Invoker::IsReady()
{
	std::string m_text;
	std::string c_text;
	std::string tmp;
	std::string key = "ABC";

	sf::Font font;

	std::ifstream *fin = nullptr;

	Command* cmd = new Cesar();

	int type = 0;
	int shift = 1;
	int isDecode = 0;

	if (!font.loadFromFile("Equal-Regular.otf"))
	{
		std::cout << "err" << std::endl;
	}
	sf::Text text_origin;
	sf::Text text_converted;
	sf::Text text_info;
	int param[] = { shift, isDecode };
	text_origin.setFillColor(sf::Color::White);
	text_origin.setCharacterSize(40); 
	text_origin.setString("File Name: ");
	text_origin.setFont(font);

	text_converted.setFillColor(sf::Color::White);
	text_converted.setCharacterSize(40);
	text_converted.setString("Code: ");
	text_converted.setFont(font);
	text_converted.setPosition(0, 50);

	text_info.setFillColor(sf::Color::Yellow);
	text_info.setCharacterSize(30);
	text_info.setString("Type: Cesar\nShift: " + std::to_string(shift));
	text_info.setFont(font);
	text_info.setPosition(1100, 0);

	while (this->window->isOpen())
	{
		this->window->clear();
		sf::Event event;
		while (this->window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				this->window->close();
			if (event.type == sf::Event::TextEntered)
			{
				if(event.text.unicode < 128)
				{
					switch (event.text.unicode)
					{
					case 8:
						m_text = m_text.substr(0, m_text.size() - 1);
						break;
					case 9:
						type = ++type % 3;
						delete cmd;
						switch (type)
						{
						case 0:
							cmd = new Cesar();
							text_info.setString("Type: Cesar\nShift: " + std::to_string(shift));
							break;
						case 1:
							cmd = new Vigner(key);
							text_info.setString("Type: Vigner\nKey: " + key);
							break;
						case 2:
							cmd = new Enigma(key);
							text_info.setString("Type: Enigma\nKey: " + key);
							break;
						default:
							break;
						}
						break;
					case 13:
						if (fin)
						{
							fin->close();
						}
						fin = new std::ifstream(m_text);
						if (!fin->is_open())
						{
							c_text = "File not found!";
						}
						else
						{
							c_text = "";
							while (!fin->eof())
							{
								std::getline(*fin, tmp);
								c_text = c_text + cmd->Execute(tmp, param) + "\n";
							}
						}
						break;
					case 27:
						this->window->close();
						break;
					case 96:
						std::cout << "Введите ключ: " << std::endl;
						std::cin >> key;
						std::cout << "Кодировать/Декодировать - 0/1: " << std::endl;
						std::cin >> isDecode;
						switch (type)
						{
						case 0:
							cmd = new Cesar();
							text_info.setString("Type: Cesar\nShift: " + std::to_string(shift));
							break;
						case 1:
							cmd = new Vigner(key);
							text_info.setString("Type: Vigner\nKey: " + key);
							break;
						case 2:
							cmd = new Enigma(key);
							text_info.setString("Type: Enigma\nKey: " + key);
							break;
						default:
							break;
						}
						break;
					default:
						m_text += event.text.unicode;
						break;
					}
					text_origin.setString("File Name: " + m_text);
					text_converted.setString("Code: \n" + c_text);
				}
			}
		}
		this->window->draw(text_origin);
		this->window->draw(text_info);
		this->window->draw(text_converted);
		this->window->display();
	}
}
