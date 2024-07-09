#include <iostream>
#include <gmock/gmock.h>

class B
{
public: 
    virtual bool bee(bool b, int i);

};

bool B::bee(bool b, int i)
{
    return false; 
}

class A {
public:
    A() = default;
    virtual ~A() = default;
    virtual void foo();
    virtual bool foo2();
    virtual bool foo3(bool b, int i);

private:
    virtual void boo();
    virtual bool boo2();
    virtual bool boo3(int i);

    friend class MockA;
};

void A::foo() {
    boo();
}

bool A::foo2() {
    return boo2();
}

bool A::foo3(bool b, int i){
    std::cout << "foo3 called" << std::endl;
    if(b)
    {
        return boo3(i);
    }
    else{
        return boo2();
    }
}


void A::boo() {
    std::cout << "boo called" << std::endl;
}

bool A::boo2() {
    std::cout << "boo2 called" << std::endl;
    return false;
}

bool A::boo3(int i) {
    std::cout << "boo3 called" << std::endl;
    return i%2;
}


class MockA : public A {
public:
    MOCK_METHOD0(boo, void());
    MOCK_METHOD0(boo2, bool());
    MOCK_METHOD1(boo3, bool(int));

    MOCK_METHOD0(foo, void());
    MOCK_METHOD0(foo2, bool());
    MOCK_METHOD2(foo3, bool(bool, int));

    void DelegateToReal() {
        ON_CALL(*this, foo()).WillByDefault([this]() { A::foo(); }); // use INVOKE from GTest
        ON_CALL(*this, foo2()).WillByDefault([this]() {return A::foo2(); });
        ON_CALL(*this, boo()).WillByDefault([this]() { A::boo(); });
        ON_CALL(*this, boo2()).WillByDefault([this]() {return A::boo2(); });
        // ON_CALL(*this, foo3).WillByDefault(::testing::Invoke(reinterpret_cast<A*>(this), &A::foo3));
        // ON_CALL(*this, boo3).WillByDefault(::testing::Invoke(reinterpret_cast<A*>(this), &A::boo3)); 
        // ON_CALL(*this, foo3).WillByDefault(::testing::Invoke(this, &A::foo3));
        // ON_CALL(*this, boo3).WillByDefault(::testing::Invoke(this, &A::boo3));      
        ON_CALL(*this, foo3).WillByDefault([this](bool b, int i) {return A::foo3(b,i); });
        ON_CALL(*this, boo3).WillByDefault([this](int i) {return A::boo3(i); });                      
    }
};

using ::testing::AtLeast;

class AFooTest : public ::testing::Test {
protected:
    ::testing::NiceMock<MockA> mockA;
};

TEST_F(AFooTest, FooCallsBoo) {
   

    // Delegate calls to the real object for non-mocked methods
    mockA.DelegateToReal();

    EXPECT_CALL(mockA, boo()).Times(AtLeast(1));


    // Call the public method foo, which should call the private method boo
    mockA.foo();
}

TEST_F(AFooTest, Foo2CallsBoo2) {
    // Delegate calls to the real object for non-mocked methods
    mockA.DelegateToReal();

    EXPECT_CALL(mockA, boo2()).Times(1).WillOnce(testing::Return(true));


    // Call the public method foo, which should call the private method boo
    EXPECT_TRUE(mockA.foo2());
}

TEST_F(AFooTest, Foo22CallsBoo2) {
    // Delegate calls to the real object for non-mocked methods
    mockA.DelegateToReal();

    EXPECT_CALL(mockA, boo2()).Times(1);


    // Call the public method foo, which should call the private method boo
    EXPECT_FALSE(mockA.foo2());
}

TEST_F(AFooTest, Foo3CallsBoo2) {
    // Delegate calls to the real object for non-mocked methods
    mockA.DelegateToReal();

    EXPECT_CALL(mockA, boo3(3)).Times(1).WillOnce(testing::Return(true));
    // EXPECT_CALL(mockA, boo2()).Times(0);

    // Call the public method foo, which should call the private method boo
    EXPECT_TRUE(mockA.foo3(true, 3));
    // mockA.foo();
}