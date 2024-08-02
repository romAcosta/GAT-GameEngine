#include "Audio.h"
#include <iostream>


bool Audio::Initialize()
{
	FMOD::System_Create(&m_audio);
	FMOD::System_Create(&m_sfx);
	
	void* extradriverdata = nullptr;
	m_audio->init(32, FMOD_INIT_NORMAL, extradriverdata);
	m_sfx->init(32, FMOD_INIT_NORMAL, extradriverdata);
    return true;
}

void Audio::Shutdown()
{
	m_audio->close();
	m_audio->close();
}

void Audio::Update()
{

	m_audio->update();
	m_sfx->update();


}

bool Audio::AddSound(const std::string& name)
{
	FMOD::Sound* sound = nullptr;
	m_audio->createSound(name.c_str(), FMOD_DEFAULT, 0, &sound);

	if (sound == nullptr) {
		std::cerr << "Could not load sound" << std::endl;
		return false;
	}

	m_sounds[name] = sound;
	return true;

}

bool Audio::PlaySound(const std::string& name)
{
	if (m_sounds.find(name) == m_sounds.end()) {
		
		if (!AddSound(name)) {
			return false;
		}
	}
	
	m_audio->playSound(m_sounds[name], 0, false, &sound_channel);
	
	

	return true;
}

void Audio::StopSound()
{
	sound_channel->stop();
}

bool Audio::AddSFX(const std::string& name)
{
	FMOD::Sound* sound = nullptr;
	m_sfx->createSound(name.c_str(), FMOD_DEFAULT, 0, &sound);

	if (sound == nullptr) {
		std::cerr << "Could not load sound" << std::endl;
		return false;
	}

	m_sounds[name] = sound;
	return true;
	
}

bool Audio::PlaySFX(bool play ,const std::string& name)
{
	if (m_sounds.find(name) == m_sounds.end()) {

		if (!AddSFX(name)) {
			return false;
		}
	}

	m_sfx->playSound(m_sounds[name], 0, play, &sfx_channel);

	
	return true;
}

void Audio::StopSFX()
{
	sfx_channel->stop();

}
