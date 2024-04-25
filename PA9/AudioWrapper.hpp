/*
	Lucas
	4/23/24

	Description: This is a header file that combines sf::SoundBuffer and sf::Sound
				into a single object

// History: 4/23/24 - Class was created and implimented initially by Lucas

*/
#include <SFML/Audio.hpp>
#include <string>
#include <iostream>

//No inheritance
class AudioWrapper {
public:
	//Audiowrapper constructor accepts filepath to audio file
	AudioWrapper(std::string inputPath = "") {
		//Sounds must be heap-allocated, otherwise they get deleted mid-audio
		buffer = new sf::SoundBuffer();
		sound = new sf::Sound();

		//Gives error in the event file cannot be found
		if (buffer->loadFromFile(inputPath)) {
			sound->setBuffer(*buffer);
		}
		else {
			std::cout << "Audio Load Error: " << inputPath << "\n";
			sound->setBuffer(*buffer);
		}
	}

	//Destructor
	~AudioWrapper();

	//Plays sound
	void play() {
		sound->play();
	}
private:
	//To play a sound, there must be a buffer and a sound
	sf::SoundBuffer* buffer;
	sf::Sound* sound;
};