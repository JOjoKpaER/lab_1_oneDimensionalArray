#pragma once

#include <stdlib.h>
#include <stdio.h>

enum SizeAction {
	Incr,
	Decr
};

class DynamicArray
{
private: 
	int length;
	float* array;

	void resize(int size, int pos, SizeAction act) {
		try {
			if (pos >= size && act != Decr || pos < 0)
			{
				throw "Incorrect pos value while resize processing. Aborting program\n";
			}
			if (act != Incr && act != Decr)
			{
				throw "Invalid action value while resize processing. Aborting program\n";
				
			}
		}
		catch (const char* exc)
		{
			printf("Exception was:\n %s", exc);
			exit(0);
		}
		float* tempArray = new float[size]();
		int i = 0;
		if (act == Incr) {
			while (i < pos)
			{
				tempArray[i] = array[i++];
			}
			while (i < size)
			{
				tempArray[i + 1] = array[i++];
			}
		}
		if (act == Decr) {
			while (i < pos)
			{
				tempArray[i] = array[i++];
			}
			while (i < size)
			{
				tempArray[i] = array[i + 1];
				i++;
			}
		}
		delete[] array;
		array = new float[size];
		array = tempArray;
		tempArray = nullptr;
		length = size;
	}

public:
	DynamicArray() {
		array = new float[0]();
		length = 0;
	}

	~DynamicArray() {
		delete[] array;
		array = nullptr;
	};

	float getAt(int pos) {
		return array[pos];
	}

	int getLength() {
		return length;
	}

	void replaceIn(int pos, float value) {
		try {
			if (pos >= length || pos < 0)
			{
				throw "Incorrect pos value while replacing in position.\n";
			}
		}
		catch (const char* exc) {
			printf("Exception was: \n %s", exc);
			return;
		}
		array[pos] = value;
	}

	void addAt(int pos, float value) {
		resize(length + 1, pos, Incr);
		array[pos] = value;
	}

	void addFirst(float value) {
		resize(length + 1, 0, Incr);
		array[0] = value;
	}

	void addLast(float value) {
		resize(length + 1, length, Incr);
		array[length - 1] = value;
	}

	void removeAt(int pos) {
		resize(length - 1, pos, Decr);
	}

	void removeFirst() {
		resize(length - 1, 0, Decr);
	}

	void removeLast() {
		resize(length - 1, length, Decr);
	}

};

