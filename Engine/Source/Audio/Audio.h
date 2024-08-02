#pragma once

#include <fmod.hpp>
#include <map>
#include <string>

class Audio {

public:
	Audio() = default;
	~Audio() = default;

	bool Initialize();
	void Shutdown();

	void Update();

	bool AddSound(const std::string& name);
	bool PlaySound(const std::string& name);
	void StopSound();

	bool AddSFX(const std::string& name);
	bool PlaySFX(bool play, const std::string& name);
	void StopSFX();

private:

	FMOD::System* m_audio{ nullptr };
	FMOD::System* m_sfx{ nullptr };
	std::map<std::string,FMOD::Sound*> m_sounds;

	FMOD::Channel *sfx_channel = nullptr;
	FMOD::Channel* sound_channel = nullptr;




};