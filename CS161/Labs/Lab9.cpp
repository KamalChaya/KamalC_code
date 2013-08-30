#include <iostream>
#include <vector>
#include <string>
using std::cin;
using std::getline;
using std::cout;
using std::string;
using std::vector;

//QUESTION: Why does cin stop at a space, but getline does not?
//Howcome when I added a \n before "Enter" at line 24, I had to press enter multiple times when inputting the string?

#define N_MOVIES 5

class movie {
	public:

		void rent_movie(vector<movie>& collection, int size) {
			for (int i = 0; i <= size - 1; i++) {
				if (collection[i].view == true) {
					cout << "\nCONFIRMED: you have rented " << collection[i].title;
					cout << "\n" << --collection[i].copies << " copies remaining";
				}
			}
		}
		
		void add_movies(vector<movie>& collection, int size) {
			for (int i = 5; i <= size - 1; i++) {
				cout << "Enter the title for movie " << i + 1 << " : ";
				getline(cin, collection[i].title);
				//cin.ignore(5000, '\n');

				cout << "Enter the rating for movie " << i + 1 << " :\n";
				getline(cin, collection[i].rating);
				//cin.ignore(5000, '\n');

				cout << "Enter the genre for movie " << i + 1 << " :\n";
				getline(cin, collection[i].genre);
				//cin.ignore(256, '\n');

				cout << "Enter the description for movie " << i + 1 << " :\n";
				getline(cin, collection[i].description);
				//cin.ignore(256, '\n');

				cout << "Enter how many copies there are for movie " << i + 1 << " :\n";
				cin >> collection[i].copies;
				cin.ignore(256, '\n');

				collection[i].view = false;
			}
		}
		
		void show_all(vector<movie>& collection, int size) {
			cout << "\nAvailable movies:";
			for (int i = 0; i <= size - 1; i++) {
				cout << "\nPress " << i << " to choose " << collection[i].title;
			}

			while (1) {
				cout << "\n>: ";
				int movieChoice = 0;
				cin >> movieChoice;
				
				if ((movieChoice >= 0) && (movieChoice <= (size - 1))) {
					while (1) {
						int userOption = 0;
						cout << "\nPress 1 to view more info about " << collection[movieChoice].title;
						cout << "\nPress 2 to rent this movie.";
						cin >> userOption;

						//Do not break out of this loop if the user is merely viewing info
						if (userOption == 1) {
							cout << "\nTitle: " << collection[movieChoice].title;
							cout << "\nGenre: " << collection[movieChoice].genre;
							cout << "\nRating: " << collection[movieChoice].rating;
							cout << "\nDescription: " << collection[movieChoice].description;
							cout << "\nRemaining Copies: " << collection[movieChoice].copies;
						}

						else if (userOption == 2) {
							collection[movieChoice].view = true;
							collection[movieChoice].copies--;
							break;
						}

						else if ((userOption != 1) || (userOption != 2))
							cout << "\nInvalid input entered; please re-enter";

					}
					break;
				}
				else 
					cout << "\nInvalid integer entered; please re-input";
			}
		}
		
		
		void show_by_genre(vector<movie>& collection, int size) {
			while (1) {
				for (int i = 0; i <= size - 1; i++) {
					cout << "\nPress " << i << " to view " << collection[i].genre << " movies.";
				}

				int genreChoice = 0;
				cout << "\n>: ";
				cin >> genreChoice;

				if ((genreChoice >= 0) && (genreChoice <= (size - 1))) {
					cout << "\nMovies of genre " << collection[genreChoice].genre << ":";
					cout << "\n" << collection[genreChoice].title;

					while (1) {
						cout << "\nPress 0 to view info about this movie.";
						cout << "\nPress 1 to rent this movie.";
						int option = 0;
						cin >> option;

						if (option == 0) {
							cout << "\nTitle: " << collection[genreChoice].title;
							cout << "\nGenre: " << collection[genreChoice].genre;
							cout << "\nRating: " << collection[genreChoice].rating;
							cout << "\nDescription: " << collection[genreChoice].description;
							cout << "\n Remaining copies: " << collection[genreChoice].copies;

						}

						else if (option == 1) {
							collection[genreChoice].view = true;
							collection[genreChoice].copies--;
							break;
						}

					}
					break;
				}

				else
					cout << "\nInvalid input; please re-enter.";
			}
		}
		
		void set_predefined_movies(vector<movie>& collection);

	private:
		int copies;
		string rating;
		string title;
		string genre;
		string description;
		bool view;
};

void inc_vector_size(int &size);

int main() {
	int size = N_MOVIES;
	bool redo;
	char yOrN;
	do {
		inc_vector_size(size); //This function determines the vector's size.
		vector<movie> collection(size);
		movie callfunc; // solely for calling member functions.
		callfunc.set_predefined_movies(collection);
		callfunc.add_movies(collection, size);

		while (1) {
			int viewChoice = 0;
			cout << "\nEnter 1 to view all movies";
			cout << "\nEnter 2 to view movies by genre";
			cout << "\n>: ";
			cin >> viewChoice;
			
			if (viewChoice == 1) {//View all 
				callfunc.show_all(collection, size);
				callfunc.rent_movie(collection, size);
				break;
			}

			
			else if (viewChoice == 2) {
				callfunc.show_by_genre(collection, size);
				callfunc.rent_movie(collection, size);
				break;
			}//View by genre*/

			else 
				cout << "\nInvalid integer entered; please re-input";
		}

		//Ask the user if they want to reuse
		while (1) {
			cout << "\nDo you want to reuse the program? (y/n)";
			cin >> yOrN;

			if ((yOrN == 'y') || (yOrN == 'Y')) {
				redo = true;
				break;
			}

			else if ((yOrN == 'n') || (yOrN == 'N')) {
				redo = false;
				break;
			}

			else 
				cout << "\nInvalid character entered; please try again";
		}
	} while (redo == true);
	return 0;
}

void movie::set_predefined_movies(vector<movie>& collection) {
	//Assign predefined movies in the vector
	collection[0].title = "Star Wars Episode IV: A New Hope";
	collection[0].rating = "PG";
	collection[0].description = "The rebel alliance plots to destroy the evil empire's death star";
	collection[0].genre = "Science Fiction";
	collection[0].view = false;
	collection[0].copies = 4;
	
	collection[1].title = "Black Hawk Down";
	collection[1].rating = "R";
	collection[1].description = "US forces try to bring order in war torn Somalia";
	collection[1].genre = "Action";
	collection[1].view = false;
	collection[1].copies = 2;
	
	collection[2].title = "Harold and Kumar go to White Castle";
	collection[2].rating = "R";
	collection[2].description = "The pot smoking duo get the munchies and decide to go to White Castle";
	collection[2].genre = "Comedy";
	collection[2].view = false;
	collection[2].copies = 6;
	
	collection[3].title = "Lord of the Rings: The fellowship of the ring";
	collection[3].rating = "PG-13";
	collection[3].description = "A band of 7 people set out to destroy dark lord sauron's evil ring";
	collection[3].genre = "Fantasy";
	collection[3].view = false;
	collection[3].copies = 4;
	
	collection[4].title = "Paranormal Activity";
	collection[4].rating = "R";
	collection[4].description = "A young couple is haunted by a supernatural presence in their home";
	collection[4].genre = "Horror";
	collection[4].view = false;
	collection[4].copies = 7;

}

void inc_vector_size(int &size) {
	char yOrN;
	int vecSizeIncrmnt = 0;

	while (1) {
		cout << "\nDo you want to add additional movies? (y/n)";
		cout << "\n(there are already 5 movies in the redbox library)";
		cout << "\n>:";
		cin >> yOrN;

			if ((yOrN == 'y') || (yOrN == 'Y')) {
				while (1) {
					cout << "\nHow many movies do you want to add? ";
					cin >> vecSizeIncrmnt;
					cin.ignore(1000, '\n');
					
					if (vecSizeIncrmnt <= 0)
						cout << "\nInvalid number entered; please re-enter.";

					else {
						size += vecSizeIncrmnt;
						break;
					}
				}
				break;
			}

			else if ((yOrN == 'n') || (yOrN == 'N')) 
				break;

			else 
				cout << "\nInvalid character entered; please try again";

	}
}