#pragma once
#include <map>
#include "movie.hpp"
#include <vector>
#include <iostream>

class MovieCollection
{
private:
    std::map<char, std::vector<Movie<double>>> moviesByLetter;

public:
    const std::map<char, std::vector<Movie<double>>> &getMoviesByLetter() const;
    std::vector<Movie<double>> getAllMovies();
    void addMovie(const Movie<double> &movie);
    void sortMovies();
    void removeMoviesOlderThan(char letter, int year);
    double getAverageTopRating();
    std::vector<Movie<double>> getMoviesByDirector(const std::string& director);
    Movie<double>* findMovieWithAverageAbove(double threshold);
};

std::ostream &operator<<(std::ostream &os, const MovieCollection &lolek);