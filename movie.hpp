#pragma once
#include <string>
#include <variant>
#include <optional>
#include <list>

template <typename RatingType>
class Movie
{
public:
    struct Director
    {
        std::string name;
        int numberOfOscars;
        Director(std::string name, int numberOfOscars) : name(name), numberOfOscars(numberOfOscars) {}
    };

private:
    std::string title;
    int year;
    std::variant<Director, std::string> director;
    std::optional<std::string> description;
    std::list<RatingType> ratings;

public:
    Movie(std::string tytul, int year, std::variant<Director, std::string> Director, std::optional<std::string> description = std::nullopt)
        : title(tytul), year(year), director(Director), description(description) {}

    std::string getTitle() { return title; }
    int getYear() { return year; }
    std::optional<std::string> getDescription() { return description; }
    std::variant<Director, std::string> getDirector() { return director; }
    std::list<RatingType> getRatings() { return ratings; }

    RatingType getAverageRating()
    {
        RatingType number = 0;
        RatingType sum = 0;
        for (auto i : ratings)
        {
            sum += i;
            number++;
        }
        return sum / number;
    }
    RatingType getTopRating()
    {
        RatingType maksimum = ratings.begin();
        for (auto i : ratings)
        {
            if (i > maksimum)
            {
                maksimum = i;
            }
        }
        return maksimum;
    }

    Movie& operator<(const Movie & mov)
    {
        if (this->title > mov.title)
        {
            return *this;
        }
        else if (this->title > mov.title)
        {
            return mov;
        }
        else
        {
            return this->year > mov.year;
        }
    }
};