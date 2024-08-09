#include "json.h"
#include "EFile.h"
#include <rapidjson/istreamwrapper.h>
#include <iostream>

namespace Json {


	bool Load(const std::string& filename, rapidjson::Document& document)
	{
		std::string buffer;
		if(!File::ReadFile(filename, buffer)) {
			return false;
		}

		std::stringstream stream(buffer);
		rapidjson::IStreamWrapper istream(stream);

		document.ParseStream(istream);
		if (!document.IsObject())
		{
			std::cerr << "Could not parse json: " << filename << std::endl;
			return false;
		}

		return true;
	}

	bool Read(const rapidjson::Value& value, const std::string& name, int& data)
	{
		if (!value.HasMember(name.c_str()) || !value[name.c_str()].IsInt()) {
			std::cerr << "Could not read json value: " << name << std::endl;
			return false;
		}

		data = value[name.c_str()].GetInt();

		return true;
	}

	bool Read(const rapidjson::Value& value, const std::string& name, bool& data)
	{
		if (!value.HasMember(name.c_str()) || !value[name.c_str()].IsBool()) {
			std::cerr << "Could not read json value: " << name << std::endl;
			return false;
		}

		data = value[name.c_str()].GetBool();
		return false;
	}

	bool Read(const rapidjson::Value& value, const std::string& name, std::string& data)
	{
		if (!value.HasMember(name.c_str()) || !value[name.c_str()].IsString()) {
			std::cerr << "Could not read json value: " << name << std::endl;
			return false;
		}

		data = value[name.c_str()].GetString();
		return false;
	}

	bool Read(const rapidjson::Value& value, const std::string& name, float& data)
	{
		if (!value.HasMember(name.c_str()) || !value[name.c_str()].IsFloat()) {
			std::cerr << "Could not read json value: " << name << std::endl;
			return false;
		}

		data = value[name.c_str()].GetFloat();
		return false;
	}

	bool Read(const rapidjson::Value& value, const std::string& name, std::vector<int>& data)
	{
		if (!value.HasMember(name.c_str()) || !value[name.c_str()].IsArray())
		{
			std::cerr << "Could not read Json value: " << name << std::endl;
			return false;
		}

		// get json array object
		auto& array = value[name.c_str()];
		// get array values
		for (rapidjson::SizeType i = 0; i < array.Size(); i++)
		{
			if (!array[i].IsNumber())
			{
				std::cerr << "Could not read Json value: " << name << std::endl;
				return false;
			}

			// get the data
			data.push_back(array[i].GetInt());
		}
		return false;
	}

	bool Read(const rapidjson::Value& value, const std::string& name, Vector2& data)
	{

		if (!value.HasMember(name.c_str()) || !value[name.c_str()].IsArray() || value[name.c_str()].Size() != 2)
		{
			std::cerr << "Could not read Json value: " << name << std::endl;
			return false;
		}

		// get json array object
		auto& array = value[name.c_str()];
		// get array values
		
			if (!array[0].IsNumber() || !array[1].IsNumber())
			{
				std::cerr << "Could not read Json value: " << name << std::endl;
				return false;
			}

			// get the data
			data.x = array[0].GetFloat();
			data.y = array[1].GetFloat();
		

		return false;
	}



}

