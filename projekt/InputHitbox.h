#ifndef INPUTHITBOX_H_
#define INPUTHITBOX_H_

class InputHitbox{
    private:
        int X,Y;
    protected:
        InputHitbox(float hX, float hY);
        virtual bool isClicked(float x, float y) = 0;
    public:
        float getX();
        float getY();
};

#endif  // INPUTHITBOX_H_
