#include "Director.h"



Director::Director()
{
}


Director::~Director()
{
}

Car* Director::build_car(brand name_of_brand) {
	Car* new_car = car_builder.build_default_car();
	switch (name_of_brand) {
	case brand::kia:
		car_builder.build_kia(new_car);
		break;
	case brand::nissan:
		car_builder.build_nissan(new_car);
		break;
	case brand::toyota:
		car_builder.build_toyota(new_car);
		break;
	case brand::vaz:
		car_builder.build_vaz(new_car);
		break;
	default:
		throw except::false_brand;
		break;
	}
	return new_car;
}