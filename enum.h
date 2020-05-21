#pragma once
//Перечисляем возможные цвета автомобилей
enum class color {
	black,
	white,
	red,
	yellow,
	blue
};

//Перечисляем возможные типы моторов
enum class engine_type {
	carburetor,
	injection
};

//Перечисляем возможные классификации кузовов по числу дверей
enum class number_of_doors {
	coupe,
	four_door,
	five_door
};

//Перечисляем возможные бренды автомобилей
enum class brand {
	vaz,
	kia,
	nissan,
	toyota
};

enum class except {
	false_color,
	false_engine_type,
	false_body_type,
	false_brand,

};