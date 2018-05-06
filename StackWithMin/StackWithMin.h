#pragma once
#include<stack>
#include<assert.h>
template <typename T>class StackWithMin
{
public:
	StackWithMin() {}
	~StackWithMin() {}
	
	T& top();
	const T& top() const;

	void push(const T& value);
	void pop();

	T& min();
	const T& min() const;

	bool empty() const;
	size_t size() const;

private:
	std::stack<T>m_data;
	std::stack<T>m_min;
};
template<typename T>void StackWithMin<T>::push(const T& value) {
	m_data.push(value);
	if (m_min.size()==0||m_min.top()>value) {
		m_min.push(value);
	}
	else {
		m_min.push(m_min.top());
	}
}
template<typename T>void StackWithMin<T>::pop() {
	assert(m_data.size()>0&&m_min.size()>0);
	m_data.pop();
	m_min.pop();
}
template<typename T>const T& StackWithMin<T>::top() const{
	assert(m_data.size() > 0);
	return m_data.top();
}
template<typename T>T& StackWithMin<T>::top(){
	assert(m_data.size() > 0);
	return m_data.top();
}

template<typename T>const T& StackWithMin<T>::min()const {
	assert(m_min.size()>0);
	return m_min.top();
}
template<typename T>T& StackWithMin<T>::min() {
	assert(m_min.size()>0);
	return m_min.top();
}

template<typename T> bool StackWithMin<T>::empty() const{
	return m_data.empty();
}

template<typename T> size_t StackWithMin<T>::size() const{
	return m_data.size();
}
