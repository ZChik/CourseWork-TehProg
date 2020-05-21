#pragma once
#include "Builder.h"

class Director {
	Builder car_builder;
public:
	Director();
	~Director();

	Car* build_car(brand name_of_brand);
};