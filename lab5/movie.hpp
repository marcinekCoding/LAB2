#pragma once
#include <string>
#include <variant>
#include <optional>
#include <list>

template < typename RatingType>
class Movie
{
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

    //konstruktory
    Movie(std::string title, int rok, auto director,std::optional<std::string> opis)
    : title(title), year(rok), 
    {
        this.description = std::move(opis);
        this.director = std::move(director);
    }
};