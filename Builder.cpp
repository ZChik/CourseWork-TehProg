#include "Builder.h"
#include <iostream>
#include <sstream>

using namespace std;

Builder::Builder() {
}


Builder::~Builder() {
}

Car* Builder::build_default_car() {
	cin.ignore(1000, '\n');
	color car_color;
	engine_type type_of_engine;
	std::string engine_volume;
	std::string size;
	std::string year;
	number_of_doors body;
	std::string model;
	std::string wheels;
	std::string trunk_volume;
	char choice{};
	cout << "Please, select a color:" << endl << "1 - Black" << endl << "2 - White" << endl << "3 - Red" << endl << "4 - Yellow" << endl << "5 - Blue" << endl;
	cin >> choice;
	switch (choice) {
	case '1':
		car_color = color::black;
		break;
	case '2':
		car_color = color::white;
		break;
	case '3':
		car_color = color::red;
		break;
	case '4':
		car_color = color::yellow;
		break;
	case '5':
		car_color = color::blue;
		break;
	default:
		throw except::false_color;
		break;
	}
	cout << "Please, select a type of engine:" << endl << "1 - Carburetor" << endl << "2 - Injection" << endl;
	getchar();
	cin >> choice;
	switch (choice) {
	case '1':
		type_of_engine = engine_type::carburetor;
		break;
	case '2':
		type_of_engine = engine_type::injection;
		break;
	default:
		throw except::false_engine_type;
		break;
	}
	cout << "Please, enter an engine volume:" << endl;
	getchar();
	getline(cin, engine_volume);
	cout << "Please, enter a size:" << endl << "Enter height:" << endl;
	string height, width, depth;
	stringstream ss;
	getline(cin, height);
	ss << height << "height ";
	cout << "Enter width:" << endl;
	getline(cin, width);
	ss << width << "width ";
	cout << "Enter depth:" << endl;
	getline(cin, depth);
	ss << depth << "depth";
	size = ss.str();
	getline(cin, size);
	cout << "Please, enter a year:" << endl;
	getline(cin, year);
	cout << "Please, select a type of body:" << endl << "1 - Coupe" << endl << "2 - Four-door body" << endl << "3 - Five-door body" << endl;
	cin >> choice;
	switch (choice) {
	case '1':
		body = number_of_doors::coupe;
		break;
	case '2':
		body = number_of_doors::four_door;
		break;
	case '3':
		body = number_of_doors::five_door;
		break;
	default:
		throw except::false_body_type;
		break;
	}
	cout << "Please, enter a model name:" << endl;
	getchar();
	getline(cin, model);
	cout << "Please, enter a wheel's brand:" << endl;
	getline(cin, wheels);
	cout << "Please, enter a trunk volume:" << endl;
	getchar();
	getline(cin, trunk_volume);

	Car* default_car = new Car(car_color, type_of_engine, engine_volume, size, year, body, model, wheels, trunk_volume);
	return default_car;
}

void Builder::build_kia(Car* default_car) {
	default_car->set_backview_mirror_heet();
}

void Builder::build_vaz(Car* default_car) {
	default_car->set_roof_trunk();
}

void Builder::build_nissan(Car* default_car) {
	default_car->set_seats_heet();
}

void Builder::build_toyota(Car* default_car) {
	default_car->set_automatic_transmisson();
}