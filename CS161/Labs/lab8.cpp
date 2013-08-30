#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;


#define NUM_MOVIES 5

struct movie_record
{
	string title;
	string rating;
	string description;
	string genre;
	bool userWantsToView;
};

void set_movies(movie_record collection[NUM_MOVIES]);
void which_movies_to_view(movie_record collection[NUM_MOVIES]);

int main()
{
	movie_record collection[NUM_MOVIES];
	set_movies(collection);

	
	
	return 0;
}

void set_movies(movie_record collection[NUM_MOVIES])
{
	//Assign values in the array
	collection[0].title = "Star Wars Episode IV: A New Hope";
	collection[0].rating = "PG";
	collection[0].description = "The rebel alliance plots to destroy the evil empire's death star";
	collection[0].genre = "Science Fiction";
	collection[0].userWantsToView = false;
	
	collection[1].title = "Black Hawk Down";
	collection[1].rating = "R";
	collection[1].description = "US forces try to bring order in war torn Somalia";
	collection[1].genre = "Action";
	collection[1].userWantsToView = false;
	
	collection[2].title = "Harold and Kumar go to White Castle";
	collection[2].rating = "R";
	collection[2].description = "The pot smoking duo get the munchies and decide to go to White Castle";
	collection[2].genre = "Comedy";
	collection[2].userWantsToView = false;
	
	collection[3].title = "Lord of the Rings: The fellowship of the ring";
	collection[3].rating = "PG-13";
	collection[3].description = "A band of 7 people set out to destroy dark lord sauron's evil ring";
	collection[3].genre = "Fantasy";
	collection[3].userWantsToView = false;
	
	collection[4].title = "Scarface";
	collection[4].rating = "R";
	collection[4].description = "A Cuban refugee comes to Miami in 1980, becoming a cocaine kingpin";
	collection[4].genre = "Action";
	collection[4].userWantsToView = false;
	
}

void which_movies_to_view(movie_record collection[NUM_MOVIES])
{
	while (1)
	{
		int movieChoice = 0;
		cout << "Enter the corresponing number for which number you want to view.\n":
		cout << " '1' for Star Wars Episode IV: A New Hope.\n";
		cout << " '2' for Black Hawk Down.\n";
		cout << " '3' for Harold and Kumar go to White Castle.\n";
		cout << " '4' for Lord of the Rings: The fellowship of the ring.\n";
		cout << " '5' for Scarface.\n";
		
		switch (movieChoice)
		{
			
		}
		
	}
	
	
}






