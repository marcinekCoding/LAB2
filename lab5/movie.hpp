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
    RatingType getAverageRating() const
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

    RatingType getTopRating() const
    {
        if (ratings.empty())
            return 0;

        RatingType max = ratings.front();
        for (const RatingType &r : ratings)
        {
            if (max < r)
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
        return this->title == movie2.title && this->year == movie2.year;
    }

    Movie<RatingType>& operator+(const RatingType& rate) {
        ratings.push_back(rate);
        return *this;
    }
};

template <typename RatingType>
std::ostream& operator<<(std::ostream& os, const Movie<RatingType> &m)
{
    os << m.getTitle() << " (" << m.getYear() << "), Director: ";
    
    auto directorVariant = m.getDirector();
    if(std::holds_alternative<typename Movie<RatingType>::Director>(directorVariant))
    {
        auto dir = std::get<typename Movie<RatingType>::Director>(directorVariant);
        os << dir.name << " (Oscars: " << dir.numberOfOscars << ")\n";
    }
    else
    {
        os << std::get<std::string>(directorVariant) << "\n";
    }

    os << "Avg: " << m.getAverageRating() << ", Top: " << m.getTopRating() << "\n";

    if(m.getDescription().has_value())
    {
        os << "Description: " << m.getDescription().value() << "\n";
    }
    
    return os;
}