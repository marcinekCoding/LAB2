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

    std::string getTitle() const { return title; }
    int getYear() const { return year; }
    std::optional<std::string> getDescription() const { return description; }
    std::variant<Director, std::string> getDirector() const { return director; }
    std::list<RatingType> getRatings() const { return ratings; }

    RatingType getAverageRating() const
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
    RatingType getTopRating() const
    {
        RatingType maksimum = ratings.front();
        for (auto i : ratings)
        {
            if (i > maksimum)
            {
                maksimum = i;
            }
        }
        return maksimum;
    }

    bool operator<(const Movie & mov)
    {
        if (this->title > mov.title)
        {
            return true;
        }
        else if (this->title < mov.title)
        {
            return false;
        }
        else
        {
            return this->year > mov.year;
        }
    }

    bool operator==(const Movie& mov)
    {
        return this->title==mov.title && this->year==mov.year;
    }

    Movie& operator+(RatingType ocena)
    {
        ratings.push_back(ocena);
        return *this;
    }

    
};
template<class RatingType>
std::ostream& operator<<(std::ostream& os, const Movie<RatingType>& movie)
{
    os<<movie.getTitle()<<" ("<<movie.getYear()<<"), Director: ";
    if (std::holds_alternative<std::string>(movie.getDirector())) 
    {
        os<<std::get<std::string>(movie.getDirector());
    }else 
    {
        os<<std::get<typename Movie<RatingType>::Director>(movie.getDirector()).name<<" (Oscars: "<<std::get<typename Movie<RatingType>::Director>(movie.getDirector()).numberOfOscars;
    }
    os<<", Avg: "<<movie.getAverageRating()<<", Top: "<<movie.getTopRating();
    if(movie.getDescription().has_value())
    {
        os<<"Description: "<<movie.getDescription().value();
    }
    return os;
}