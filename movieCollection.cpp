#include "moveCollection.hpp"

auto& MovieCollection::getMoviesByLetter()
{
    return moviesByLetter;
}

std::vector<Movie<double>> MovieCollection::getAllMovies()
{
    std::vector<Movie<double>> allMovies;
    
    for(const auto& [c,movie] : moviesByLetter)
    {
        allMovies.insert(allMovies.end(),movie.begin(),movie.end());
    }
    return allMovies;
}

void MovieCollection::addMovie(const Movie<double>& movie)
{
    char c = movie.getTitle()[0];
    moviesByLetter[c].push_back(movie);
}
