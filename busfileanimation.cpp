#include "include.h"
void animate(Node** matrix, int SIZE)
{ 
    //pass in Size
    int asize = 5;
    int count = 0;
    int maxorder = 0;
    for(int i = 0; i < asize; i++)
    {
        for(int j = 0; j < asize; j++)
        {
            if(matrix[i][j].get_order()>maxorder)
            {
                maxorder = matrix[i][j].get_order();
            }
        }
    }
    Coord* coords= new Coord[maxorder];
    for(int i = 0; i < asize; i++)
    {
        for(int j = 0; j < asize; j++)
        {
            if(matrix[i][j].get_order()!=0)
            {
                coords[matrix[i][j].get_order()-1].x = j;
                coords[matrix[i][j].get_order()-1].y = i;
            }
        }
    }
    Picture pic("bus.png");
    Animation anim("animation.gif", asize*pic.width(), asize*pic.height());
    cout << "width: "<<pic.width() << endl;
    cout << "height: "<<pic.height() << endl;
    int currentx =0;
    int currenty =0;
    std::cout<<"------------------ANIMATION-------------------\n";
    for(int j = 0; j< maxorder;j++)
    {
        std::cout<<coords[j].x<<", "<<coords[j].y<<"\n";
        if (matrix[coords[j].y][coords[j].x].get_reset())
        {
            std::cout<<"reset happens at: "<<coords[j].x<<", "<<coords[j].y<<"\n";
            currentx = 0;
            currenty = 0;
        }
        //RIGHT
        if(coords[j].y==currenty && coords[j].x-currentx>0){
            //std::cout<<"currentx "<< currentx<<" coordx : "<< coords[j].x<<"\n";
            for (int i = currentx*pic.width(); i < coords[j].x*pic.width(); i++)
            {
                //std::cout<<i<<" "<<currenty*pic.height()<<";\n";
                anim.add(pic, i, currenty*pic.height());
                anim.frame();
            }
            std::cout<<"right \n";
        }
        //DOWN RIGHT
        else if(coords[j].y-currenty>0 && coords[j].x-currentx>0){
            //std::cout<<"currenty "<< currenty<<" coordy : "<< coords[j].y<<"\n";
            int sizecount = 0;
            for (int i = currenty*pic.height(); i < coords[j].y*pic.height(); i++)
            {
                //std::cout<<currentx*pic.width()<<" "<<i<<";\n";
                anim.add(pic, currentx*pic.width()+sizecount, i);
                anim.frame();
                sizecount++;
            }
            std::cout<<"down \n";
        }
        //DOWN
        else if(coords[j].y-currenty>0 && coords[j].x==currentx){
            //std::cout<<"currenty "<< currenty<<" coordy : "<< coords[j].y<<"\n";
            for (int i = currenty*pic.height(); i < coords[j].y*pic.height(); i++)
            {
                //std::cout<<currentx*pic.width()<<" "<<i<<";\n";
                anim.add(pic, currentx*pic.width(), i);
                anim.frame();
            }
            std::cout<<"down \n";
        }
        //DOWN LEFT
        else if(coords[j].y-currenty>0 && coords[j].x-currentx<0){
            //std::cout<<"currenty "<< currenty<<" coordy : "<< coords[j].y<<"\n";
            int sizecount = 0;
            for (int i = currenty*pic.height(); i < coords[j].y*pic.height(); i++)
            {
                //std::cout<<currentx*pic.width()<<" "<<i<<";\n";
                anim.add(pic, currentx*pic.width()-sizecount, i);
                anim.frame();
                sizecount++;
            }
            std::cout<<"down left \n";
        }
        //LEFT
        else if(coords[j].y==currenty && coords[j].x-currentx<0){
            //std::cout<<"currentx "<< currentx<<" coordx : "<< coords[j].x<<"\n";
            for (int i = currentx*pic.width(); i > coords[j].x*pic.width(); i--)
            {
                //std::cout<<i<<" "<<currenty*pic.height()<<";\n";
                anim.add(pic, i, currenty*pic.height());
                anim.frame();
            }
            std::cout<<"left \n";
        }
        // UP LEFT
        else if(coords[j].y-currenty<0 && coords[j].x-currentx<0){
            //std::cout<<"currentx "<< currentx<<" coordx : "<< coords[j].x<<"\n";
            int sizecount = 0;
            for (int i = currentx*pic.width(); i > coords[j].x*pic.width(); i--)
            {
                //std::cout<<i<<" "<<currenty*pic.height()<<";\n";
                anim.add(pic, i, currenty*pic.height()-sizecount);
                anim.frame();
                sizecount++;
            }
            std::cout<<"up left \n";
        }
        
        //UP
        else if(coords[j].y-currenty<0 && coords[j].x==currentx){
            //std::cout<<"currenty "<< currenty<<" coordy : "<< coords[j].y<<"\n";
            for (int i = currenty*pic.height(); i > coords[j].y*pic.height(); i--)
            {
                //std::cout<<currentx*pic.width()<<" "<<i<<";\n";
                anim.add(pic, currentx*pic.width(), i);
                anim.frame();
            }
            std::cout<<"up;\n";
        }
        //UP RIGHT
        else if(coords[j].y-currenty<0 && coords[j].x-currentx>0){
            //std::cout<<"currenty "<< currenty<<" coordy : "<< coords[j].y<<"\n";
            int sizecount = 0;
            for (int i = currenty*pic.height(); i > coords[j].y*pic.height(); i--)
            {
                //std::cout<<currentx*pic.width()<<" "<<i<<";\n";
                anim.add(pic, currentx*pic.width()+sizecount, i);
                anim.frame();
                sizecount++;
            }
            std::cout<<"up right \n";
        }
        currentx =  coords[j].x;
        currenty = coords[j].y;
        std::cout<<"-----------------------\n";
        
    }
    /**
    for(int j = 0; j< maxorder;j++)
    {
        std::cout<<coords[j].x<<", "<<coords[j].y<<"\n";
        if (matrix[coords[j].y][coords[j].x].get_reset())
        {
            std::cout<<"reset happens at: "<<coords[j].x<<", "<<coords[j].y<<"\n";
            currentx = 0;
            currenty = 0;
        }
        
        if(coords[j].x-currentx>0){
            //std::cout<<"currentx "<< currentx<<" coordx : "<< coords[j].x<<"\n";
            for (int i = currentx*pic.width(); i < coords[j].x*pic.width(); i++)
            {
                //std::cout<<i<<" "<<currenty*pic.height()<<";\n";
                anim.add(pic, i, currenty*pic.height());
                anim.frame();
            }
            std::cout<<"right \n";
        }
        if(coords[j].x-currentx<0){
            //std::cout<<"currentx "<< currentx<<" coordx : "<< coords[j].x<<"\n";
            for (int i = currentx*pic.width(); i > coords[j].x*pic.width(); i--)
            {
                //std::cout<<i<<" "<<currenty*pic.height()<<";\n";
                anim.add(pic, i, currenty*pic.height());
                anim.frame();
            }
            std::cout<<"left \n";
        }
        currentx =  coords[j].x;
        if(coords[j].y-currenty>0){
            //std::cout<<"currenty "<< currenty<<" coordy : "<< coords[j].y<<"\n";
            for (int i = currenty*pic.height(); i < coords[j].y*pic.height(); i++)
            {
                //std::cout<<currentx*pic.width()<<" "<<i<<";\n";
                anim.add(pic, currentx*pic.width(), i);
                anim.frame();
            }
            std::cout<<"down;\n";
        }
        if(coords[j].y-currenty<0){
            //std::cout<<"currenty "<< currenty<<" coordy : "<< coords[j].y<<"\n";
            for (int i = currenty*pic.height(); i > coords[j].y*pic.height(); i--)
            {
                //std::cout<<currentx*pic.width()<<" "<<i<<";\n";
                anim.add(pic, currentx*pic.width(), i);
                anim.frame();
            }
            std::cout<<"up;\n";
        }
        currenty = coords[j].y;
        std::cout<<"-----------------------\n";
        
    }
    */
}

