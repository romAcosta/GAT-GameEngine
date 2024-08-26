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

	bool Read(const rapidjson::Value& value, const std::string& name, int& data, bool isRequired )
	{
		if (!value.HasMember(name.c_str()) || !value[name.c_str()].IsInt()) {
			std::cerr << "Could not read json value: " << name << std::endl;
			return false;
		}

		data = value[name.c_str()].GetInt();

		return true;
	}

	bool Read(const rapidjson::Value& value, const std::string& name, bool& data, bool isRequired)
	{
		if (!value.HasMember(name.c_str()) || !value[name.c_str()].IsBool()) {
			if(isRequired) std::cerr << "Could not read json value: " << name << std::endl;
			return false;
		}

		data = value[name.c_str()].GetBool();
		return false;
	}

	bool Read(const rapidjson::Value& value, const std::string& name, std::string& data, bool isRequired)
	{
		if (!value.HasMember(name.c_str()) || !value[name.c_str()].IsString()) {
			if (isRequired) std::cerr << "Could not read json value: " << name << std::endl;
			return false;
		}

		data = value[name.c_str()].GetString();
		return false;
	}

	bool Read(const rapidjson::Value& value, const std::string& name, float& data, bool isRequired)
	{
		if (!value.HasMember(name.c_str()) || !value[name.c_str()].IsNumber()) {
			if (isRequired) std::cerr << "Could not read json value: " << name << std::endl;
			return false;
		}

		data = value[name.c_str()].GetFloat();
		return false;
	}

	bool Read(const rapidjson::Value& value, const std::string& name, std::vector<int>& data, bool isRequired)
	{
		if (!value.HasMember(name.c_str()) || !value[name.c_str()].IsArray())
		{
			if (isRequired) std::cerr << "Could not read Json value: " << name << std::endl;
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

	bool Read(const rapidjson::Value& value, const std::string& name, std::vector<std::string>& data, bool isRequired)
	{
		if (!value.HasMember(name.c_str()) || !value[name.c_str()].IsArray())
		{
			if (isRequired) std::cerr << "Could not read Json value: " << name << std::endl;
			return false;
		}

		// get json array object
		auto& array = value[name.c_str()];
		// get array values
		for (rapidjson::SizeType i = 0; i < array.Size(); i++)
		{
			if (!array[i].IsString())
			{
				std::cerr << "Could not read Json value: " << name << std::endl;
				return false;
			}

			// get the data
			data.push_back(array[i].GetString());
		}
		return false;
	}

	bool Read(const rapidjson::Value& value, const std::string& name, Rect& data, bool isRequired)
	{
		if (!value.HasMember(name.c_str()) || !value[name.c_str()].IsArray() || value[name.c_str()].Size() != 4)
		{
			if (isRequired) std::cerr << "Could not read Json value: " << name << std::endl;
			return false;
		}

		// get json array object
		auto& array = value[name.c_str()];
		// get array values


		// get the data
		data.x = array[0].GetFloat();
		data.y = array[1].GetFloat();
		data.w = array[2].GetFloat();
		data.h = array[3].GetFloat();

	
		return true;
	}

	bool Read(const rapidjson::Value& value, const std::string& name, std::vector<int> data, bool isRequired)
	{
		return false;
	}

	bool Read(const rapidjson::Value& value, const std::string& name, Vector2& data, bool isRequired)
	{

		if (!value.HasMember(name.c_str()) || !value[name.c_str()].IsArray() || value[name.c_str()].Size() != 2)
		{
			if (isRequired) std::cerr << "Could not read Json value: " << name << std::endl;
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

