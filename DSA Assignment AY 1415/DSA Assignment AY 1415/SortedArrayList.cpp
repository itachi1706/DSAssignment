#include <string>
#include <iostream>
#include "SortedArrayList.h"
using namespace std;

SortedArrayList::SortedArrayList()
{
	size = 0;
}
bool SortedArrayList::add(SongItem song)
{
	bool success = size < SA_MAX_SIZE;
	if (success)
	{
		SAList[size] = song;
		size++;
	}
	return success;
}

void SortedArrayList::remove(int index)
{
	bool success = (index >= 1) && (index <= size);
	if (success)
	{
		for (int pos = index + 1; pos <= size; pos++)
			SAList[pos - 2] = SAList[pos - 1];
		size--;
	}
}
void SortedArrayList::display()
{
	SongItem item;
	for (int i = 0; i < getLength(); i++)
	{
		item = get(i);
		cout << "TrackID: " << item.getTID() << endl;
		cout << "Artist Name: " << item.getAName() << endl;
		cout << "Song Title: " << item.getMxmTitle() << endl;
		cout << "MxmID: " << item.getMxmTid() << endl;
		cout << "" << endl;
	}
}
void SortedArrayList::display(int index)
{
	SongItem item;
	item = get(index);
	cout << "TrackID: " << item.getTID() << endl;
	cout << "Artist Name: " << item.getAName() << endl;
	cout << "Song Title: " << item.getMxmTitle() << endl;
	cout << "MxmID: " << item.getMxmTid() << endl;
	cout << "" << endl;
}
int SortedArrayList::sqSearch(Song SAList[], string target) //search using TrackID presumably. Can be changed
{
	int n = getLength();
	for (int i = 0; i < n; i++)
	{
		if (SAList[i].getTID() == target)//found
			return i;
		else if (SAList[i].getTID() > target)//not found
			return -1;
	}
	return -1;
}
int SortedArrayList::binSearch(Song SAList[], string target)
{
	int n = getLength();
	int mid, first = 0, last = n - 1;
	while (first<=last)
	{
		mid = (first + last) / 2;
		if (SAList[mid].getTID() == target) //found
			return mid;
		else if (target < SAList[mid].getTID()) //searching through first half
			last = mid - 1;
		else
			first = mid + 1;//searching through second half
	}
	return -1; //not found
}
SongItem SortedArrayList::get(int index)
{
	SongItem item;
	bool success = (index <= size);
	if (success)
		item = SAList[index];
	return item;
}
bool SortedArrayList::isEmpty()
{
	return (size == 0);
}
int SortedArrayList::getLength()
{
	return size;
}