#pragma once
#include "enum.h"
#include <string>
#include <fstream>

class Car {
	color car_color;
	engine_type type_of_engine;
	std::string engine_volume;
	std::string size;
	std::string year;
	number_of_doors body;
	std::string model;
	std::string wheels;
	std::string trunk_volume;

	bool roof_trunk; //ВАЗ
	bool backview_mirrors_heet; //КИА
	bool seats_heet; //Ниссан
	bool automatic_transmission; //Тойота

	brand brand_name;
public:
	Car();
	Car(color col,
		engine_type en_type,
		std::string en_vol,
		std::string size,
		std::string year,
		number_of_doors body,
		std::string model,
		std::string wheels,
		std::string trunk);
	~Car();
	void print_to_file(std::ofstream& output_file);
	void read_from_file(std::ifstream& input_file);
	void print_on_screen();

	void set_roof_trunk();
	void set_backview_mirror_heet();
	void set_seats_heet();
	void set_automatic_transmisson();

	brand get_brand_name();
};
