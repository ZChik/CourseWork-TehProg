#pragma once
#include "Car.h"

class Builder {
public:
	Builder();
	~Builder();

	Car* build_default_car();

	void build_kia(Car* default_car);
	void build_vaz(Car* default_car);
	void build_nissan(Car* default_car);
	void build_toyota(Car* default_car);
}; 
