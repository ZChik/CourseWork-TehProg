#pragma once
//����������� ��������� ����� �����������
enum class color {
	black,
	white,
	red,
	yellow,
	blue
};

//����������� ��������� ���� �������
enum class engine_type {
	carburetor,
	injection
};

//����������� ��������� ������������� ������� �� ����� ������
enum class number_of_doors {
	coupe,
	four_door,
	five_door
};

//����������� ��������� ������ �����������
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