package main

import "fmt"

type MinStack struct {
	m_Capacity int
	m_Size     int
	m_Array    []int
	m_Min      int
}

func NewStack(capacity int) *MinStack {
	return &MinStack{capacity, 0, make([]int, capacity), 0}
}

func (s *MinStack) Push(x int) {
	if s.m_Size == s.m_Capacity {
		return
	}

	if s.m_Size == 0 {
		s.m_Min = x
		s.m_Array[0] = x
	} else if x < s.m_Min {
		s.m_Array[s.m_Size] = x*2 - s.m_Min
		s.m_Min = x
	} else {
		s.m_Array[s.m_Size] = x
	}

	s.m_Size++
}

func (s *MinStack) Pop() {
	if s.m_Size == 0 {
		return
	}

	n := s.m_Array[s.m_Size-1]
	if n < s.m_Min {
		if s.m_Size != 1 {
			s.m_Min = s.m_Min*2 - n
		}
	}

	s.m_Size--
}

func (s *MinStack) Top() int {
	if s.m_Size == 0 {
		return -1
	}

	n := s.m_Array[s.m_Size-1]
	if n < s.m_Min {
		return s.m_Min
	}

	return n
}

func (s *MinStack) GetMin() int {
	return s.m_Min
}

func main() {
	s := NewStack(10)
	s.Push(3)
	s.Push(8)
	s.Push(1)
	s.Push(2)
	s.Push(-1)
	s.Push(7)
	s.Push(-9)
	fmt.Println(s.GetMin())
	s.Pop()
	fmt.Println(s.Top())
	fmt.Println(s.GetMin())
	s.Pop()
	s.Pop()
	fmt.Println(s.Top())
	fmt.Println(s.GetMin())
	s.Pop()
	fmt.Println(s.Top())
	fmt.Println(s.GetMin())
	s.Pop()
	fmt.Println(s.Top())
	fmt.Println(s.GetMin())
}
