#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Book
{
	static const int BUFFER_SIZE = 20;
	int Id;
	char Title[BUFFER_SIZE];
	char Author[BUFFER_SIZE];
	float Price;
	int Quantity;
};


/*int lenth(char* name)
{
	int out = 0;
	while (name[out] != '\0')
	{
		++out;
	}
	return out;
}

void swap(Book& book1, Book& book2)
{
	Book temp;
	temp = book2;
	book2 = book1;
	book1 = temp;
}

char* concatenate(char* first, char* second)
{
	int lenthfirst = lenth(first);
	int lenthsecond = lenth(second);
	char* out = new char[lenthsecond + lenthfirst +1];
	for (int i = 0; i < lenth(first); ++i)
	{

		out[i] = first[i];
	}

	for (int i = 0; i < lenth(second); ++i)
	{
		out[lenth(first) + i] = second[i];
	}
	out[lenthfirst + lenthsecond] = '\0';

	first = out;
	return first;
}*/




int main()
{
	Book books[5] = {
			{ 1, "Clarissa", "Samuel Richardson",8.75,1000 },
			{ 2, "Robinson Crusoe", "Daniel Defoe",7.5,1000 },
			{ 3, "Tom Jones", "Henry Fielding",6.55,1000 },
			{ 4, "Emma", "Jane Austen",4.1625,1000 },
			{ 5, "Frankenstein", "Mary Shelley",1.425,1000 },

	};
	ofstream fout("books.bin", istream::out | istream::binary);
	fout.write(reinterpret_cast<char*>(&books[0]), sizeof(Book) * 5);
	fout.close();

	int choice=0;

	while (choice != 6)
	{
		setlocale(LC_ALL, "Russian");
		cout << "��� �� �� ������ �������?" << endl << "1: �������� �����." << endl << "2: ������������� �����." << endl << "3: ����� �����." << endl << "4: ������ ����." << endl << "5: ����������." << endl << "6: �����." << endl;
		cin >> choice;
		ifstream fin("books.bin", istream::in | istream::binary);
		fin.seekg(0, ios_base::end);
		int size = fin.tellg();
		int count = size / sizeof(Book);
		fin.seekg(0, ios_base::beg);

		Book* books1 = new Book[count];
		fin.read(reinterpret_cast<char*>(books1), sizeof(Book) * count);
		fin.close();
		if (choice == 1)
		{
			fout.open("books.bin", istream::app);
			cout << "������� Id, ��������, ������, ��������� � �����" << endl;
			Book book;
			cin >> book.Id >> book.Title >> book.Author >> book.Price >> book.Quantity;

			fout.write(reinterpret_cast<char*>(&book), sizeof(Book));
			fout.close();


			fin.open("books.bin", ios_base::out);
			fin.read(reinterpret_cast<char*>(books1), sizeof(Book) * count);
			fin.close();

			for (int i = 0;i < count;++i)
			{
				cout << books1[i].Id << " " << books1[i].Title << " " << books1[i].Author << " " << books1[i].Price << " " << books1[i].Quantity << endl;
			}
			
		}
		if (choice == 2)
		{
			fin.open("books.bin", ios_base::out);
			fin.read(reinterpret_cast<char*>(books1), sizeof(Book) * count);
			fin.close();
			int Id;
			cin >> Id;
			Book* ptr = nullptr;
			for (int i = 0; i < count; ++i)
			{
				if (Id == books1[i].Id)
				{
					ptr = &books1[i];
					break;
				}
			}

			if (ptr == nullptr)
			{
				cout << "student with Id " << Id << " not found" << endl;
			}
			else
			{
				cin >> ptr->Title >> ptr->Author >> ptr->Price >> ptr->Quantity;
				fout.open("books.bin", istream::out && ios_base::trunc);
				fout.write(reinterpret_cast<char*>(&books1[0]), sizeof(Book) * count);
				fout.close();
				fin.open("books.bin", ios_base::out);
				fin.read(reinterpret_cast<char*>(books1), sizeof(Book) * count);
				fin.close();

				for (int i = 0;i < count;++i)
				{
					cout << books1[i].Id << " " << books1[i].Title << " " << books1[i].Author << " " << books1[i].Price << " " << books1[i].Quantity << endl;
				}
			}
		}
		if (choice == 3)
		{
			fin.open("books.bin", ios_base::out);
			fin.read(reinterpret_cast<char*>(books1), sizeof(Book) * count);
			fin.close();
			string name;
			cin >> name;

			Book* ptr = nullptr;
			for (int i = 0; i < count; ++i)
			{
				string temp(books1[i].Title);
				if (name == temp)
				{
					ptr = &books1[i];
					break;
				}
			}

			if (ptr == nullptr)
			{
				cout << "student with name " << name << " not found" << endl;
			}
			else
			{
				cout << ptr->Id << " " << ptr->Title << " " << ptr->Author << " " << ptr->Price << " " << ptr->Quantity << endl;
			}


		}
		/*if (choice == 4)
		{
			fin.open("books.bin", ios_base::out);
			fin.read(reinterpret_cast<char*>(books1), sizeof(Book) * count);
			fin.close();
			int x = 0;
			bool flag = true;
			while (flag)
			{
				flag = false;
				for (int i = 0; i < size - 1 - x; ++i)
				{
					if (concatenate(books1[i].Author, books1[i].Title) > concatenate(books1[i].Author, books1[i].Title))
					{
						swap(books1[i], books1[i + 1]);
					}
				}
				++x;
			}
		}*/
		if (choice == 5)
		{
			fin.open("books.bin", ios_base::out);
			fin.read(reinterpret_cast<char*>(books1), sizeof(Book) * count);
			fin.close();
			int sum_price = 0;
			int sum_quantity = 0;



			for (int i = 0; i < count; ++i)
			{
				sum_price += books1[i].Price;
				sum_quantity += books1[i].Quantity;
			}

			cout << "Summary price of books: " << sum_price << ", summary quantity: " << sum_quantity << std::endl;
		}
	}


 }