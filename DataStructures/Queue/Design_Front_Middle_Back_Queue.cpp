class node
{
public:
    node *next;
    node *prev;
    int val;

    node(int val)
    {
        this->next = nullptr;
        this->prev = nullptr;
        this->val = val;
    }
};

class FrontMiddleBackQueue
{
public:
    int size;
    node *start;
    node *end;
    node *mid;

    FrontMiddleBackQueue()
    {
        this->size = 0;
        this->start = nullptr;
        this->end = nullptr;
        this->mid = nullptr;
    }

    void pushFront(int val)
    {
        node *temp = new node(val);
        if (size == 0)
        {
            start = temp;
            mid = temp;
            end = temp;
        }
        else if (size % 2 == 0)
        {
            start->prev = temp;
            temp->next = start;
            start = temp;
        }
        else if (size % 2 != 0)
        {
            start->prev = temp;
            temp->next = start;
            start = temp;
            mid = mid->prev;
        }

        size++;
    }

    void pushMiddle(int val)
    {
        node *temp = new node(val);
        if (size == 0)
        {
            start = temp;
            mid = temp;
            end = temp;
        }

        else if (size % 2 == 0)
        {
            temp->next = mid->next;
            mid->next->prev = temp;
            mid->next = temp;
            temp->prev = mid;
            mid = mid->next;
        }

        else if (size % 2 != 0)
        {
            temp->next = mid;
            temp->prev = mid->prev;
            if (size != 1)
                mid->prev->next = temp;
            mid->prev = temp;
            mid = temp;
        }

        if (size == 1)
            start = temp;

        size++;
    }

    void pushBack(int val)
    {
        node *temp = new node(val);
        if (size == 0)
        {
            start = temp;
            mid = temp;
            end = temp;
        }
        else if (size % 2 == 0)
        {
            end->next = temp;
            temp->prev = end;
            end = temp;
            mid = mid->next;
        }
        else if (size % 2 != 0)
        {
            end->next = temp;
            temp->prev = end;
            end = temp;
        }

        size++;
    }

    int popFront()
    {
        if (size != 0)
        {
            mid = mid->next;
            int temp = start->val;
            start = start->next;
            if (size == 1)
            {
                end = nullptr;
            }
            if (size != 1)
            {
                start->prev->next = nullptr;
                start->prev = nullptr;
            }

            size--;
            return temp;
        }
        return -1;
    }

    int popMiddle()
    {
        if (size != 0)
        {
            int temp = mid->val;

            node *tempmid = mid;

            if (size % 2 == 0)
            {
                mid = mid->next;
            }
            if (size % 2 != 0)
            {
                mid = mid->prev;
            }

            if (size == 2)
            {
                mid->prev = NULL;
                start->next = NULL;
                start = mid;
            }

            if (size == 1)
            {
                start = nullptr;
                end = nullptr;
            }
            if (size != 1)
            {
                if (size != 2)
                {
                    tempmid->prev->next = tempmid->next;
                    tempmid->next->prev = tempmid->prev;
                    tempmid->prev = nullptr;
                    tempmid->next = nullptr;
                }
            }

            size--;

            return temp;
        }
        return -1;
    }

    int popBack()
    {
        if (size != 0)
        {
            int temp = end->val;
            end = end->prev;
            if (size == 1)
            {
                start = nullptr;
            }
            if (size != 1)
            {
                end->next->prev = nullptr;
                end->next = nullptr;
            }
            if (size % 2 != 0)
                mid = mid->prev;
            size--;
            return temp;
        }
        return -1;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */