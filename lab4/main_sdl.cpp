#include <iostream>
#include "SDL2/SDL.h"
#include <cmath>
#include "matrix.h"


//#include "VM.h"
class Engine
{
private:
    bool flagToExit = false;
    int height;
    int width; // размер окна в пикселях
    std::string value;
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    int Init()
    {
        if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
        {
            std::cout << SDL_GetError() << "\n";
            return -2;
        }

        window = SDL_CreateWindow("Laba3", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, height, width,
                                  SDL_WINDOW_OPENGL);
        if (window == NULL)
        {
            std::cout << SDL_GetError() << "\n";
            return -3;
        }
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        return 10;
    };

    void Render(Vector &v1, Vector &v2, Vector &v3, Vector &v4)
    {


    	
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

       SDL_RenderDrawLine(renderer, v1[0], v1[1], v2[0], v2[1]);
        SDL_RenderDrawLine(renderer, v2[0], v2[1], v3[0], v3[1]);
       SDL_RenderDrawLine(renderer, v3[0], v3[1], v4[0], v4[1]);
       SDL_RenderDrawLine(renderer, v4[0], v4[1], v1[0], v1[1]);
        SDL_RenderPresent(renderer);
    };

    void PollsEvent()
    {
        SDL_Event event;
        SDL_PollEvent(&event);
        switch (event.type)
        {
        case SDL_QUIT:
            flagToExit = true;
            break;

        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                flagToExit = true;
                break;
            case SDLK_SPACE:
                std::cout << "i'm here"
                          << "\n";
                break;
            
            default:
                break;
            
            }
            break;
        default:
            break;
        }
    };

    void Update(){
        /*
         * В данной функции реализуется логика вызова методов
         * для операций над матрицами и векторами.
         *
         *
         * */
         
         
    };

public:

	friend Matrix operator * (Vector &r);
    Engine(int height, int width)
    {
        this->height = height;
        this->width = width;
    };

    ~Engine(){};

    void Run(Vector &vec1, Vector &vec2, Vector &vec3, Vector &vec4)
    {
        Init();
        while (!flagToExit)
        {
            PollsEvent();
            Update();
            Render(vec1, vec2, vec3, vec4);
        }
        SDL_DestroyRenderer(renderer);
        std::cout << "renderer memory finalized"
                  << "\n";
        SDL_DestroyWindow(window);
        std::cout << "window memory finalized"
                  << "\n";
        SDL_Quit();
        std::cout << "SDL memory finalized"
                  << "\n";
    }
};



int main(int argc, char *argv[])
{
	int n;

        Vector vect1, vect2, vect3, vect4;
	vect1.push(100);
    	vect1.push(400);
    	vect2.push(140);
    	vect2.push(400);
    	vect3.push(140);
    	vect3.push(500);
    	vect4.push(100);
    	vect4.push(500);
    	

    	bool flag =false;
	while(!flag)
	{
	cout <<"Нажмите 0, чтобы завершить программу\n" << "Нажмите 1, чтобы повернуть фигуру\n"<<"Нажмите 2, чтобы увеличить фигуру\n"<<"Нажмите 3, если хотите сдвинуть фигуру\n"<<"Нажмите 4, если хотите просто нарисовать фигуру\n";
	cin >> n;
	switch(n)
	{
	case 0:
	flag = true;
	break;
	
	case 1:
	{
	float grad;
	cout << "На какой угол хотите повернуть? От 0 до 90!!!!\n";
	
	cin >> grad;
	Matrix matr(2,2);
	matr[0][0] = cos(3.1416*grad/180);
    	matr[0][1] = sin(3.1416*grad/180);
    	matr[1][0] = -sin(3.1416*grad/180);
    	matr[1][1] = cos(3.1416*grad/180);
    	
    	Vector v1 = matr*vect1;
    	Vector v2 = matr*vect2;
    	Vector v3 = matr*vect3;
    	Vector v4 = matr*vect4;
    	
    	Engine visualMath = Engine(1000, 1000);
    	visualMath.Run(v1,v2,v3,v4);
	break;
	}
	case 2:
	{
	float grad;
	cout << "Во сколько хотите изменить масштаб фигуры? От 0 до 2\n";
	cin >> grad;
	Matrix matr(2,2);
	matr[0][0] = grad;
    	matr[0][1] = 0;
    	matr[1][0] = 0;
    	matr[1][1] = grad;
    	
    	Vector v1 = matr*vect1;
    	Vector v2 = matr*vect2;
    	Vector v3 = matr*vect3;
    	Vector v4 = matr*vect4;
    	
    	Engine visualMath = Engine(1000, 1000);
    	visualMath.Run(v1,v2,v3,v4);
    	break;
	}
	case 3:
	{
	float x,y;
	cout << "Введите насколько сдвинуть по оси x\n";
	cin >> x;
	cout << "Введите насколько сдвинуть по оси y\n";
	cin >> y;
	
	Vector v1;
	v1.push(vect1[0] + x);
	v1.push(vect1[1] + y);
	Vector v2;
	v2.push(vect2[0] + x);
	v2.push(vect2[1] + y);
	Vector v3;
	v3.push(vect3[0] + x);
	v3.push(vect3[1] + y);
	Vector v4;
	v4.push(vect4[0] + x);
	v4.push(vect4[1] + y);
	
	
	Engine visualMath = Engine(1000, 1000);
    	visualMath.Run(v1,v2,v3,v4);
	
	break;
	}
	case 4:
	Engine visualMath = Engine(1000, 1000);
    	visualMath.Run(vect1,vect2,vect3,vect4);
	break;
	}
	}

    	

    
    return 0;
}
