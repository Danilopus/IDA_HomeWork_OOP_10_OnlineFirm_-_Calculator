#pragma once
#include <string>
#include <iostream>

class ClientPerson
{
	static long long _CLIENT_COUNT;
	std::string _name;
	std::string _adress;
	double _account_statement;
	int _account_number;
	enum class _CLIENT_STATUS { temporary, constant } _client_status;

public:
	static auto Get_CLIENT_COUNT() { return _CLIENT_COUNT; }
	ClientPerson(std::string name, double account_statement)
	{
		_account_number = ++_CLIENT_COUNT;
		_name = name;
		_account_statement = account_statement;
		_client_status = _CLIENT_STATUS::constant;
		_adress = "HomeAdress";
	}
	ClientPerson(const ClientPerson& obj_to_init_by_copy)
	{
		*this = obj_to_init_by_copy;
		_client_status = _CLIENT_STATUS::temporary;
		_adress = "temporaryAdress";
	}


	~ClientPerson()
	{
		if (_client_status == _CLIENT_STATUS::constant) _CLIENT_COUNT--;
	}

	// Shows ---------------------------------------------------------------
	void ShowInfo()
	{
		std::cout << "\n" << "_name           " << _name;
		std::cout << "\n" << "_adress         " << _adress;
		std::cout << "\n" << "_account_number " << _account_number;
		std::cout << "\n" << "_account_state  " << _account_statement;
		std::cout << "\n" << "_client_status  " << int(_client_status);
	}
	//static std::string Open_Interface_Info();
	//static std::vector<int>& Get_Operation_Info();

};




