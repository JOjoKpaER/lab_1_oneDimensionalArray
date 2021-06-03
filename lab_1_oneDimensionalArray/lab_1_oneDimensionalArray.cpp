#include <stdlib.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <Windows.h>

#include <DynamicArray.h>

#define EPS 0.000001f

int main()
{
	DynamicArray dynArray = DynamicArray();
	std::string path;
	printf("Input path to values file\n");
	std::cin >> path;
	if (path == "0")
		path = "values.txt";
	std::ifstream inFile(path);
	if (!inFile.is_open())
	{
		printf("Cannot open file.\n");
		return 0;
	}
	std::string line;
	while (std::getline(inFile, line)) {
		dynArray.addLast(std::stof(line));
	}
	inFile.close();
	for (int i = 0; i < dynArray.getLength(); i++)
		printf("i: %i value: %f\n", i, dynArray.getAt(i));
	std::string avaibleFuncs = "======================================\nAddFirst\nAddLast\nAddAt\nRemoveFirst\nRemoveLast\nRemoveAt\nAddAfter\nRemoveAll\nListArray\nRandomInput\nEnd\n======================================";
	std::string funcToExecute;
	while (true)
	{
		std::cout << avaibleFuncs << std::endl;
		std::cout << "Input next funtion name to execute" << std::endl;
		std::cin >> funcToExecute;
		/*===============================================================*/
		if (funcToExecute == "AddFirst")
		{
			float value;
			bool b = true;
			do {
				std::cout << "Input value: ";
				std::cin >> value;
				if (std::cin.fail()) {
					std::cin.clear();
					std::cin.ignore(32767, '\n');
					std::printf("Incorrect value\n");
					Sleep(500);
					b = true;
				}
				else {
					b = false;
					std::cin.ignore(32767, '\n');
				}
			} while (b);
			dynArray.addFirst(value);
			printf("Value %f was putted in %i position\n", dynArray.getAt(0), 0);
			continue;
		}
		/*===============================================================*/
		if (funcToExecute == "AddLast")
		{
			float value;
			bool b = true;
			do {
				std::cout << "Input value: ";
				std::cin >> value;
				if (std::cin.fail()) {
					std::cin.clear();
					std::cin.ignore(32767, '\n');
					std::printf("Incorrect value\n");
					Sleep(500);
					b = true;
				}
				else {
					b = false;
					std::cin.ignore(32767, '\n');
				}
			} while (b);
			dynArray.addLast(value);
			printf("Value %f was putted in %i position\n", dynArray.getAt(dynArray.getLength() - 1), dynArray.getLength() - 1);
			continue;
		}
		/*===============================================================*/
		if (funcToExecute == "AddAt")
		{
			float value;
			int pos;
			bool b = true;
			do {
				std::cout << "Input value: ";
				std::cin >> value;
				if (std::cin.fail()) {
					std::cin.clear();
					std::cin.ignore(32767, '\n');
					std::printf("Incorrect value\n");
					Sleep(500);
					b = true;
				}
				else {
					b = false;
					std::cin.ignore(32767, '\n');
				}
			} while (b);
			b = true;
			do {
				std::cout << "Input position: ";
				std::cin >> pos;
				if (std::cin.fail()) {
					std::cin.clear();
					std::cin.ignore(32767, '\n');
					std::printf("Incorrect value\n");
					Sleep(500);
					b = true;
				}
				else {
					b = false;
					std::cin.ignore(32767, '\n');
				}
			} while (b);
			dynArray.addAt(pos, value);
			printf("Value %f was putted in %i position\n", dynArray.getAt(pos), pos);
			continue;
		}
		/*===============================================================*/
		if (funcToExecute == "RemoveFirst")
		{
			printf("Value %f was removed from %i position\n", dynArray.getAt(0), 0);
			dynArray.removeFirst();
			continue;
		}
		/*===============================================================*/
		if (funcToExecute == "RemoveLast")
		{
			printf("Value %f was removed in %i position\n", dynArray.getAt(dynArray.getLength()-1), dynArray.getLength() - 1);
			dynArray.removeLast();
			continue;
		}
		/*===============================================================*/
		if (funcToExecute == "RemoveAt")
		{
			int pos;
			bool b = true;
			do {
				std::cout << "Input position: ";
				std::cin >> pos;
				if (std::cin.fail()) {
					std::cin.clear();
					std::cin.ignore(32767, '\n');
					std::printf("Incorrect value\n");
					Sleep(500);
					b = true;
				}
				else {
					b = false;
					std::cin.ignore(32767, '\n');
				}
			} while (b);
			printf("Value %f was removed from %i position\n", dynArray.getAt(pos), pos);
			dynArray.removeAt(pos);
			continue;
		}
		/*===============================================================*/
		if (funcToExecute == "AddAfter")
		{
			float value;
			bool b = true;
			do {
				std::cout << "Input value after which new element should be placed: ";
				std::cin >> value;
				if (std::cin.fail()) {
					std::cin.clear();
					std::cin.ignore(32767, '\n');
					std::printf("Incorrect value\n");
					Sleep(500);
					b = true;
				}
				else {
					b = false;
					std::cin.ignore(32767, '\n');
				}
			} while (b);
			int pos = -1;
			for (int i = 0; i < dynArray.getLength(); i++)
			{
				if (abs(dynArray.getAt(i)- value) < EPS)
				{
					pos = i;
					break;
				}
			}
			if (pos == -1)
			{
				printf("Cannot find value %f in array\n", value);
				continue;
			}
			float newValue;
			b = true;
			do {
				std::cout << "Input value of new element ";
				std::cin >> newValue;
				if (std::cin.fail()) {
					std::cin.clear();
					std::cin.ignore(32767, '\n');
					std::printf("Incorrect value\n");
					Sleep(500);
					b = true;
				}
				else {
					b = false;
					std::cin.ignore(32767, '\n');
				}
			} while (b);
			dynArray.addAt(pos+1, newValue);
			printf("Value %f was putted in %i position\n", dynArray.getAt(pos+1), pos+1);
			continue;
		}
		/*===============================================================*/
		if (funcToExecute == "RemoveAll") {
			float value;
			bool b = true;
			do {
				std::cout << "Input value";
				std::cin >> value;
				if (std::cin.fail()) {
					std::cin.clear();
					std::cin.ignore(32767, '\n');
					std::printf("Incorrect value\n");
					Sleep(500);
					b = true;
				}
				else {
					b = false;
					std::cin.ignore(32767, '\n');
				}
			} while (b);
			bool found = false;
			for (int i = 0; i < dynArray.getLength(); i++)
			{
				if (abs(dynArray.getAt(i)- value) < EPS)
				{
					dynArray.removeAt(i);
					found = true;
					printf("Value was removed at %i\n", i);
				}
			}
			if (!found)
			{
				printf("Cannot find value %f in array\n", value);
			}
			continue;
		}
		/*===============================================================*/
		if (funcToExecute == "ListArray")
		{
			for (int i = 0; i < dynArray.getLength(); i++)
				printf("i: %i value: %f\n", i, dynArray.getAt(i));
			continue;
		}
		/*===============================================================*/
		if (funcToExecute == "RandomInput")
		{

			float value = (float) (std::rand() * std::rand()) / (float) std::rand();

			dynArray.addFirst(value);
			printf("Value %f was putted in %i position\n", dynArray.getAt(0), 0);

			value = (float)(std::rand() * std::rand()) / (float)std::rand();
			
			dynArray.addLast(value);
			printf("Value %f was putted in %i position\n", dynArray.getAt(dynArray.getLength() - 1), dynArray.getLength() - 1);
			
			value = (float)(std::rand() * std::rand()) / (float)std::rand();
			int pos = std::rand() % dynArray.getLength();

			dynArray.addAt(pos, value);
			printf("Value %f was putted in %i position\n", dynArray.getAt(pos), pos);

			value = dynArray.getAt(std::rand()%dynArray.getLength());
			float newValue = (float)(std::rand() * std::rand()) / (float)std::rand();
			pos = -1;
			for (int i = 0; i < dynArray.getLength(); i++)
			{
				if (abs(dynArray.getAt(i)- value) < EPS)
				{
					pos = i;
					break;
				}
			}
			if (pos == -1)
			{
				printf("Cannot find value %f in array\n", value);
				continue;
			}
			dynArray.addAt(pos + 1, newValue);
			printf("Value %f was putted in %i position\n", dynArray.getAt(pos), pos);
			continue;
		}
		/*===============================================================*/
		if (funcToExecute == "End")
		{
			break;
		}
		std::cout << "\nThis function is not avaible\n" << std::endl;
		Sleep(1000);
	}
	return 0;
}



