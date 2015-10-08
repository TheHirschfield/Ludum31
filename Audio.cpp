#include "Audio.h"
#include "Debug.h"
#include "Resources.h"

Audio::Audio()
{
}
Audio::~Audio()
{
}

void Audio::init(){

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096) < 0){
		debug.report("Error Initilizing Sound");
	}
	else{
		debug.report("Successfully Initilizing Sound");
	}

	resources.loadSounds();
	/*Mix_VolumeMusic(20);
	Mix_PlayMusic(resources.testMusic, -1);*/

}

void Audio::loadSound(string path){
	
}

void Audio::playMusic(Mix_Music* musicPlay){

	//Play the music
	//Mix_Volume(-1, 100);
	Mix_VolumeMusic(100);
	if (Mix_PlayMusic(musicPlay, 0) == -1){
		printf("Mix_PlayMusic: %s\n", Mix_GetError());
	}
	else{	
		debug.report("play");
	}
		//debug.report("Please Play Music");
}

Audio audio;