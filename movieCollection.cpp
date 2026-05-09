#include "moveCollection.hpp"
#include <algorithm>
#include <numeric>

const std::map<char, std::vector<Movie<double>>> &MovieCollection::getMoviesByLetter() const
{
    return moviesByLetter;
}

std::vector<Movie<double>> MovieCollection::getAllMovies()
{
    std::vector<Movie<double>> allMovies;

    for (const auto &[c, movie] : moviesByLetter)
    {
        allMovies.insert(allMovies.end(), movie.begin(), movie.end());
    }
    return allMovies;
}

void MovieCollection::addMovie(const Movie<double> &movie)
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
    for (auto &[c, movies] : moviesByLetter)
    {
        std::sort(movies.begin(), movies.end());
    }
}

struct Compare
{
    char letter;
    int year;

    Compare(int year) : year(year) {}

    bool operator()(const Movie<double> &m) const
    {
        return m.getYear() < year;
    }
};
void MovieCollection::removeMoviesOlderThan(char letter, int year)
{
    auto new_end = std::remove_if(moviesByLetter[letter].begin(), moviesByLetter[letter].end(), Compare(year));
    moviesByLetter[letter].erase(new_end, moviesByLetter[letter].end());
}

double MovieCollection::getAverageTopRating()
{
    struct rating
    {
        double operator()(double cur, const Movie<double> &m) const
        {
            return cur += m.getTopRating();
        }
    };
    double srednia = 0;
    std::vector<Movie<double>> wektorek = getAllMovies();
    double ratings = std::accumulate(wektorek.begin(), wektorek.end(), 0.0, rating());
    return ratings / wektorek.size(); 
}

std::vector<Movie<double>> MovieCollection::getMoviesByDirector(const std::string &director)
{
    struct to_copy
    {
        const std::string &director;
        to_copy(const std::string &director) : director(director) {}

        bool operator()(const Movie<double> &m)
        {
            return m.getDirector() == director;
        }
    };
    std::vector<Movie<double>> dirvec;
    std::vector<Movie<double>> allvec = getAllMovies();
    std::copy_if(allvec.begin(), allvec.end(), std::back_inserter(dirvec), to_copy(director));
    return dirvec;
}

Movie<double> MovieCollection::findMovieWithAverageAbove(double threshold)
{
    struct cases{
        double warunek;
        cases(double war) : warunek(war) {}

        bool operator()(const Movie<double>& m)
        {
            if(m.getAverageRating()>warunek)
            {
                return true;
            }else{
                return false;
            }
        }
    };
    std::vector<Movie<double>> wektorek = getAllMovies();
    auto movie_found = std::find_if(wektorek.begin(),wektorek.end(),cases(threshold));
    return *movie_found;
}
