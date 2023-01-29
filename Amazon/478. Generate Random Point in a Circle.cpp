class Solution {
public:
    Solution(double radius_in, double x_center_in, double y_center_in)
        : radius{radius_in},
          x_center{x_center_in},
          y_center{y_center_in}
    {}
    
    vector<double> randPoint() noexcept
    {
        double x,y;
        do
        {
            x = std::uniform_real_distribution{x_center - radius, x_center + radius}(mt);
            y = std::uniform_real_distribution{y_center - radius, y_center + radius}(mt);       
        }while((x-x_center)*(x-x_center)+(y-y_center)*(y-y_center) > radius * radius); // drop points outside the circle
        return {x, y};
    }
private:
    double const radius;
    double const x_center;
    double const y_center;
    std::mt19937 mt{std::random_device{}()};
};
