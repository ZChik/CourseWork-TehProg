#include "Car.h"
#include <iostream>

using namespace std;

Car::Car() {
}


Car::~Car() {
}

Car::Car(color col, engine_type en_type, std::string en_vol, std::string size, std::string year, number_of_doors body, std::string model, std::string wheels, std::string trunk) {
	this->car_color = col;
	this->type_of_engine = en_type;
	this->engine_volume = en_vol;
	this->size = size;
	this->year = year;
	this->body = body;
	this->model = model;
	this->wheels = wheels;
	this->trunk_volume = trunk;
	this->automatic_transmission = false;
	this->backview_mirrors_heet = false;
	this->seats_heet = false;
	this->roof_trunk = false;
}

brand Car::get_brand_name() {
	return this->brand_name;
}

void Car::set_roof_trunk() {
	cin.ignore(1000, '\n');
	this->brand_name = brand::vaz;
	char choice;
	cout << "Set a roof trunk?" << endl << "1 - Yes" << endl << "2 - No" << endl;
	cin >> choice;
	switch (choice) {
	case '1':
		this->roof_trunk = true;
		break;
	default:
		break;
	}
}

void Car::set_backview_mirror_heet() {
	cin.ignore(1000, '\n');
	this->brand_name = brand::kia;
	char choice;
	cout << "Set a backview mirror's heet?" << endl << "1 - Yes" << endl << "2 - No" << endl;
	cin >> choice;
	switch (choice) {
	case '1':
		this->backview_mirrors_heet = true;
		break;
	default:
		break;
	}
}

void Car::set_seats_heet() {
	cin.ignore(1000, '\n');
	this->brand_name = brand::nissan;
	char choice;
	cout << "Set a seats heet ?" << endl << "1 - Yes" << endl << "2 - No" << endl;
	cin >> choice;
	switch (choice) {
	case '1':
		this->backview_mirrors_heet = true;
		break;
	default:
		break;
	}
}

void Car::set_automatic_transmisson() {
	cin.ignore(1000, '\n');
	this->brand_name = brand::toyota;
	char choice;
	cout << "Set an automatic transmission ?" << endl << "1 - Yes" << endl << "2 - No" << endl;
	cin >> choice;
	switch (choice) {
	case '1':
		this->backview_mirrors_heet = true;
		break;
	default:
		break;
	}
}

void Car::print_to_file(std::ofstream& output_file) {
	cin.ignore(1000, '\n');
	switch (this->car_color) {
	case color::black:
		output_file << "Black" << endl;
		break;
	case color::blue:
		output_file << "Blue" << endl;
		break;
	case color::red:
		output_file << "Red" << endl;
		break;
	case color::white:
		output_file << "White" << endl;
		break;
	case color::yellow:
		output_file << "Yellow" << endl;
		break;
	default:
		break;
	}
	switch (this->type_of_engine) {
	case engine_type::carburetor:
		output_file << "Carburetor" << endl;
		break;
	case engine_type::injection:
		output_file << "Injection" << endl;
		break;
	default:
		break;
	}
	output_file << this->engine_volume << endl;
	output_file << this->size << endl;
	output_file << this->year << endl;
	switch (this->body) {
	case number_of_doors::coupe:
		output_file << "Coupe" << endl;
		break;
	case number_of_doors::four_door:
		output_file << "Four" << endl;
		break;
	case number_of_doors::five_door:
		output_file << "Five" << endl;
		break;
	default:
		break;
	}
	output_file << this->model << endl;
	output_file << this->wheels << endl;
	output_file << this->trunk_volume << endl;
	if (this->roof_trunk) {
		output_file << "1" << endl;
	}
	else {
		output_file << "0" << endl;
	}
	if (this->backview_mirrors_heet) {
		output_file << "1" << endl;
	}
	else {
		output_file << "0" << endl;
	}
	if (this->seats_heet) {
		output_file << "1" << endl;
	}
	else {
		output_file << "0" << endl;
	}
	if (this->automatic_transmission) {
		output_file << "1" << endl;
	}
	else {
		output_file << "0" << endl;
	}
}

void Car::read_from_file(std::ifstream &input_file) {
	string temp;
	getline(input_file, temp);
	if (temp == "Yellow") {
		this->car_color = color::yellow;
	}
	else {
		if (temp == "Red") {
			this->car_color = color::red;
		}
		else {
			if (temp == "Black") {
				this->car_color = color::black;
			}
			else {
				if (temp == "White") {
					this->car_color = color::white;
				}
				else {
					if (temp == "Blue") {
						this->car_color = color::blue;
					}
					else {
						throw except::false_color;
					}
				}
			}
		}
	}
	getline(input_file, temp);
	if (temp == "Carburetor") {
		this->type_of_engine = engine_type::carburetor;
	}
	else {
		if (temp == "Injection") {
			this->type_of_engine = engine_type::injection;
		}
		else {
			throw except::false_engine_type;
		}
	}
	getline(input_file, this->engine_volume);
	getline(input_file, this->size);
	getline(input_file, this->year);
	getline(input_file, temp);
	if (temp == "Coupe") {
		this->body = number_of_doors::coupe;
	}
	else {
		if (temp == "Four") {
			this->body = number_of_doors::four_door;
		}
		else {
			if (temp == "Five") {
				this->body = number_of_doors::five_door;
			}
			else {
				throw except::false_body_type;
			}
		}
	}
	getline(input_file, this->model);
	getline(input_file, this->wheels);
	getline(input_file, this->trunk_volume);
	getline(input_file, temp);
	if (temp == "1") {
		this->roof_trunk = true;
	}
	else {
		this->roof_trunk = false;
	}
	getline(input_file, temp);
	if (temp == "1") {
		this->backview_mirrors_heet = true;
	}
	else {
		this->backview_mirrors_heet = false;
	}
	getline(input_file, temp);
	if (temp == "1") {
		this->seats_heet = true;
	}
	else {
		this->seats_heet = false;
	}
	getline(input_file, temp);
	if (temp == "1") {
		this->automatic_transmission = true;
	}
	else {
		this->automatic_transmission = false;
	}
}

void Car::print_on_screen() {
	cout << "Color: ";
	switch (car_color) {
	case color::yellow:
		cout << "Yellow" << endl;
		break;
	case color::black:
		cout << "Black" << endl;
		break;
	case color::red:
		cout << "Red" << endl;
		break;
	case color::blue:
		cout << "Blue" << endl;
		break;
	case color::white:
		cout << "White" << endl;
		break;
	default:
		break;
	}

	cout << "Engine: ";
	switch (type_of_engine) {
	case engine_type::carburetor:
		cout << "Carburetor" << endl;
		break;
	case engine_type::injection:
		cout << "Injection" << endl;
		break;
	default:
		break;
	}

	cout << "Engine volume: " << engine_volume << endl;
	cout << "Size: " << size << endl;
	cout << "Year: " << year << endl;
	cout << "Body: ";
	switch (body) {
	case number_of_doors::coupe:
		cout << "Coupe" << endl;
		break;
	case number_of_doors::four_door:
		cout << "Four-door" << endl;
		break;
	case number_of_doors::five_door:
		cout << "Five-door" << endl;
		break;
	default:
		break;
	}

	cout << "Model: " << model << endl;
	cout << "Wheel's brand: " << wheels << endl;
	cout << "Trunk volume: " << trunk_volume << endl;

	switch (roof_trunk) {
	case true:
		cout << "Roof trunk" << endl;
		break;
	default:
		break;
	}
	switch (backview_mirrors_heet) {
	case true:
		cout << "Bacview mirror's heet" << endl;
		break;
	default:
		break;
	}
	switch (seats_heet) {
	case true:
		cout << "Seats heet" << endl;
		break;
	default:
		break;
	}
	switch (automatic_transmission) {
	case true:
		cout << "Automatic transmisson" << endl;
		break;
	default:
		cout << "Manual transmisson" << endl;
		break;
	}
}