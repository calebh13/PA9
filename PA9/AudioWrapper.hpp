#include <SFML/Audio.hpp>
#include <string>
#include <iostream>


class AudioWrapper {
public:
	AudioWrapper(std::string inputPath) {
		buffer = new sf::SoundBuffer();
		sound = new sf::Sound();

		if (buffer->loadFromFile(inputPath)) {
			sound->setBuffer(*buffer);
		}
		else {
			std::cout << "Audio Load Error: " << inputPath << "\n";
		}
	}

	~AudioWrapper();

	void play() {
		sound->play();
	}
private:
	sf::SoundBuffer* buffer;
	sf::Sound* sound;
};