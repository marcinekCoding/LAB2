#pragma once
#include <map>
#include "movie.hpp"
#include <vector>

class MovieCollection
{
private:
    std::map<char, std::vector<Movie<double>>> moviesByLetter;

public:
    auto &getMoviesByLetter();
    std::vector<Movie<double>> getAllMovies();
    void addMovie(const Movie<double> &movie);
};