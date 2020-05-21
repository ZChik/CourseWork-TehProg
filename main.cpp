#include "Director.h"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main() {
	try {
		vector<Car*> cars;
		Director main_director;
		char choice{};
		unsigned num_of_notes{};
		bool work = true;
		cout << "Do you want to read a car information from files? 1 - Yes 2 - No " << endl;
		cin >> choice;
		switch (choice) {
		case '1': {
			for (int j = 0; j < 4; ++j) {
				std::ifstream input;
				switch (j) {
				case 0:
					while (!input.is_open()) {
						input.open("nissan.txt");
					}
					break;
				case 1:
					while (!input.is_open()) {
						input.open("toyota.txt");
					}
					break;
				case 2:
					while (!input.is_open()) {
						input.open("kia.txt");
					}
					break;
				case 3:
					while (!input.is_open()) {
						input.open("vaz.txt");
					}
					break;
				default:
					break;
				}
				string config;
				getline(input, config);
				num_of_notes = atoi(config.c_str());
				for (unsigned i = 0; i < num_of_notes; ++i) {
					Car* temp = new Car();
					temp->read_from_file(input);
					cars.push_back(temp);
				}
			}
			break;
		}
		case '2': {
			cout << "Please, enter a number of cars, that need to be added in list:" << endl;
			cin >> num_of_notes;
			for (unsigned i = 0; i < num_of_notes; ++i) {
				cout << "Choose a brand: " << endl << "1 - Kia" << endl << "2 - VAZ" << endl << "3 - Nissan" << endl << "4 - Toyota" << endl;
				cin >> choice;
				switch (choice) {
				case '1':
					cars.push_back(main_director.build_car(brand::kia));
					break;
				case '2':
					cars.push_back(main_director.build_car(brand::vaz));
					break;
				case '3':
					cars.push_back(main_director.build_car(brand::nissan));
					break;
				case '4':
					cars.push_back(main_director.build_car(brand::toyota));
					break;
				default:
					break;
				}
			}
			break;
		}
		default:
			break;
		}
		while (work) {
			cout << "Select a function: " << endl << "1 - Print information on screen" << endl << "2 - Create a new car" << endl << "3 - Delete a car" << endl << "4 - exit" << endl;
			cin >> choice;
			switch (choice) {
			case '1': {
				for (int i = 0; i < cars.size(); ++i) {
					cars[i]->print_on_screen();
				}
				break;
			}
			case '2': {
				cout << "Choose a brand: " << endl << "1 - Kia" << endl << "2 - VAZ" << endl << "3 - Nissan" << endl << "4 - Toyota" << endl;
				cin >> choice;
				switch (choice) {
				case '1':
					cars.push_back(main_director.build_car(brand::kia));
					break;
				case '2':
					cars.push_back(main_director.build_car(brand::vaz));
					break;
				case '3':
					cars.push_back(main_director.build_car(brand::nissan));
					break;
				case '4':
					cars.push_back(main_director.build_car(brand::toyota));
					break;
				default:
					break;
				}
				break;
			}
			case '3': {
				for (int i = 0; i < cars.size(); ++i) {
					cout << i << endl;
					cars[i]->print_on_screen();
				}
				int num{};
				cout << "Enter an index of choosen car:" << endl;
				cin >> num;
				cars.erase(cars.begin() + num);
				break;
			}
			case '4': {
				ofstream output_kia("kia.txt");
				ofstream output_nissan("nissan.txt");
				ofstream output_toyota("toyota.txt");
				ofstream output_vaz("vaz.txt");
				int counter_kia{}, counter_nissan{}, counter_vaz{}, counter_toyota{};
				for (int i = 0; i < cars.size(); ++i) {
					switch (cars[i]->get_brand_name()) {
					case brand::kia:
						counter_kia++;
						break;
					case brand::nissan:
						counter_nissan++;
						break;
					case brand::toyota:
						counter_toyota++;
						break;
					case brand::vaz:
						counter_vaz++;
						break;
					}
					output_kia << counter_kia << endl;
					output_nissan << counter_nissan << endl;
					output_toyota << counter_toyota << endl;
					output_vaz << counter_vaz << endl;
				}
				for (int i = 0; i < cars.size(); ++i) {
					switch (cars[i]->get_brand_name()) {
					case brand::kia:
						cars[i]->print_to_file(output_kia);
						break;
					case brand::nissan:
						cars[i]->print_to_file(output_nissan);
						break;
					case brand::toyota:
						cars[i]->print_to_file(output_toyota);
						break;
					case brand::vaz:
						cars[i]->print_to_file(output_vaz);
						break;
					}
				}
				for (int i = 0; i < cars.size(); ++i)
					delete cars[i];
				work = false;
				break;
			}
			}
		}
	}
	catch (except my_except) {
		switch (my_except) {
		case except::false_body_type:
			cout << "False body type" << endl;
			break;
		case except::false_brand:
			cout << "False brand" << endl;
			break;
		case except::false_color:
			cout << "False color" << endl;
			break;
		case except::false_engine_type:
			cout << "False engine type" << endl;
			break;
		default:
			break;
		}
	}
	return 0;
}