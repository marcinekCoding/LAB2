#pragma once
#include <string>
#include <variant>
#include <optional>
#include <list>
#include <iostream>

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
    // konstruktory
    Movie(std::string title, int rok, std::variant<Director, std::string> director, std::optional<std::string> opis = std::nullopt)
        : title(title), year(rok), director(director), description(opis) {}

    // getter
    std::string getTitle() const { return title; }
    int getYear() const { return year; }
    std::optional<std::string> getDescription() const { return description; }
    std::variant<Director, std::string> getDirector() const { return director; }
    std::list<RatingType> getRatings() const { return ratings; }

    // etap 2
    int getAverageRating()
    {
        RatingType mean = 0;
        RatingType elements = 0;

        if (ratings.empty())
            return 0;

        for (const RatingType &r : ratings)
        {
            elements++;
            mean += r;
        }
        return mean / elements;
    }

    int getTopRating()
    {
        if (ratings.empty())
            return 0;

        RatingType max = list.begin();
        for (RatingType &r : ratings)
        {
            if (max <= r)
            {
                max = r;
            }
        }
        return max;
    }

    bool operator<(const Movie<RatingType> &movie2) const
    {
        if (this->title != movie2.title)
        {
            return this->title < movie2.title;
        }
        return this->year < movie2.year;
    }
    bool operator==(const Movie<RatingType> &movie2) const
    {
        return this->title < movie2.title && this->year < movie2.year;
    }
    Movie<RatingType>& operator+(RatingType& rate) {
        ratings.push_back(rate);
    }
};

template <typename RatingType>
void operator<<(const Movie<RatingType> &m)
{
    std::cout<<m.getTitle<<" ("<<m.getYear()<<") , Director: "<<m.getDirector()<<std::endl;
    if(std::holds_alternative<Director>(director))
    {
        std::cout<<"(Oscars: )"<<director.numberOfOscars;
    }
    std::cout<<"Avg: "<<m.getAverageRating()<<", Top: "<<m.getTopRating();
    
}