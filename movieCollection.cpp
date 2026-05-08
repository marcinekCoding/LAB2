#include "moveCollection.hpp"

auto& MovieCollection::getMoviesByLetter()
{
    return moviesByLetter;
}

std::vector<Movie<double>> MovieCollection::getAllMovies()
{
    std::vector<
}

void MovieCollection::addMovie(const Movie<double>& movie)
{
    char c = movie.getTitle()[0];
    moviesByLetter.insert(std::make_pair(c,movie));
}
