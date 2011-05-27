#ifndef _INC_OP_THREAD_H
#define _INC_OP_THREAD_H

#include    "Thread.h"

#define     BLOCK_SIZE  20

// This class is child class of abstract Thread which is templatized.
// It contains two operands, and operation enum, and placeholder for result of the
// computation.
template <class T, class M>
class OperationThread   : public Thread {
    
private:
    std::vector<T>        op1, op2; 
    std::vector<M>        *result;  //  TODO directly store the result in the output vector
    std::vector<short>    *carry;
    int                   st_idx ,end_idx;
    OPERATION operation;

public:

    //  input paramete is the thread ID
    OperationThread(int);
    ~OperationThread();

    //  runs when a thread waiting on a condition variable is scheduled i.e. thread state
    //  is THREAD_RUNNING
    void run();
    
    // getter setter for operand 1 
    std::vector<T>      getOp1();
    void   setOp1(std::vector<T> op1);

    // getter setter for operand 2 
    std::vector<T>      getOp2();
    void   setOp2(std::vector<T> op2);
    
    // getter setter for start index 
    int     getStIdx();
    void    setStIdx(int);

    // getter setter for end index 
    int     getEndIdx();
    void    setEndIdx(int);

    // setter for carry
    std::vector<short>*   getCarry();
    void    setCarry(std::vector<short>*);

    //  setter getter for result
    std::vector<M>*   getResult();
    void    setResult(std::vector<M>*);
    
    // getter setter for operation
    OPERATION        getOperation();
    void             setOperation(OPERATION);


};

template <class T, class M>
OperationThread<T, M>  ::  OperationThread(int tid):Thread(tid)    {
}

template <class T, class M>
OperationThread<T, M>  ::  ~OperationThread()    {
    //Thread::~Thread();
}

template <class T, class M>
inline std::vector<T>
OperationThread<T, M>  ::  getOp1()    {
    return this->op1;
}

template <class T, class M>
inline void
OperationThread<T, M>  ::  setOp1(std::vector<T> op1)    {
    this->op1 = op1;
}

template <class T, class M>
inline std::vector<T>
OperationThread<T, M>  ::  getOp2()    {
    return this->op2;
}

template <class T, class M>
inline void
OperationThread<T, M>  ::  setOp2(std::vector<T> op2)    {
    this->op2 = op2;
}

template <class T, class M>
inline int
OperationThread<T, M> :: getStIdx()   {
    return this->st_idx;
}

template <class T, class M>
inline void
OperationThread<T, M> :: setStIdx(int st_idx)   {
    this->st_idx = st_idx;
}

template <class T, class M>
inline int
OperationThread<T, M> :: getEndIdx()   {
    return this->end_idx;
}

template <class T, class M>
inline void
OperationThread<T, M> :: setEndIdx(int end_idx)   {
    this->end_idx = end_idx;
}

template <class T, class M>
inline std::vector<short>* 
OperationThread<T, M> :: getCarry() {
    return this->carry;
}

template <class T, class M>
inline void
OperationThread<T, M> :: setCarry(std::vector<short> *carry)   {
    this->carry = carry;
}

template <class T, class M>
inline std::vector<M>*
OperationThread<T, M>  ::  getResult()    {
    return this->result;
}

template <class T, class M>
inline void 
OperationThread<T, M>  ::  setResult(std::vector<M>* result)    {
    this->result = result;
}

template <class T, class M>
inline OPERATION
OperationThread<T, M>  ::  getOperation()  {
    return this->operation;    
}

template <class T, class M>
inline void
OperationThread<T, M>  ::  setOperation(OPERATION operation)  {
   this->operation = operation;
}


template <class T, class M>
void
OperationThread<T, M> :: run()   {
    
    this->setThreadState(THREAD_RUNNING);
    switch (operation)  {
        case ADD:
            for (int i = 0, j = st_idx; i < end_idx - st_idx; i++)  {
                this->result->at(j++) = (M)this->op1[i] + (M)this->op2[i]; 
            }
            break;
        case SUB:
            for (int i = 0, j = st_idx; i < end_idx - st_idx; i++)  {
                this->result->at(j++) = (M)this->op1[i] - (M)this->op2[i]; 
            }
            break;
        case AND:
            for (int i = 0, j = st_idx; i < end_idx - st_idx; i++)  {
                this->result->at(j++) = (M)this->op1[i] & (M)this->op2[i]; 
            }
            break;
        case OR:
            for (int i = 0, j = st_idx; i < end_idx - st_idx; i++)  {
                this->result->at(j++) = (M)this->op1[i] | (M)this->op2[i]; 
            }
            break;
        case XOR:
            for (int i = 0, j = st_idx; i < end_idx - st_idx; i++)  {
                this->result->at(j++) = (M)this->op1[i] ^ (M)this->op2[i]; 
            }
            break;
        case NOT:
            for (int i = 0, j = st_idx; i < end_idx - st_idx; i++)  {
                this->result->at(j++) = (M)~this->op1[i]; 
            }
            break;
    }
    this->setThreadState(THREAD_DONE);
}

#endif  // _INC_OP_THREAD_H
