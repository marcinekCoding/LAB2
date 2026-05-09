#include "moveCollection.hpp"
#include <algorithm>

const std::map<char, std::vector<Movie<double>>>& MovieCollection::getMoviesByLetter() const
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

std::ostream &operator<<(std::ostream &os, const MovieCollection &lolek)
{
    for (const auto &[c, movie] : lolek.getMoviesByLetter())
    {
        os << "=== " << c << " ===\n";
        for (const auto &i : movie)
        {
            os << i << "\n";
        }
    }
    return os;
}

void MovieCollection::sortMovies()
{
    for(auto& [c,movies]: moviesByLetter)
    {
        std::sort(movies.begin(),movies.end());
    }
}

struct Compare
{
    char letter; 
    int year;    

    Compare(int year) : year(year) {}

    bool operator()(const Movie<double>& m) const
    {
        return m.getYear() < year;
    }
};
void MovieCollection::removeMoviesOlderThan(char letter, int year)
{
    auto new_end = std::remove_if(moviesByLetter[letter].begin(),moviesByLetter[letter].end(),Compare(year));
    moviesByLetter[letter].erase(new_end,moviesByLetter[letter].end());

}
