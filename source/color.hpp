# ifndef COLOR_HPP
# define COLOR_HPP

struct Color
{
    public:
    Color (float r, float g, float b);
    Color (float f);

    //private:    
    float r_;
    float g_;
    float b_;
};
# endif // COLOR_HPP