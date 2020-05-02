#pragma once
#include <bitset>


namespace MiaofansCommonLibrary
{
	template<size_t N>
	class BigInt: public std::bitset<N>
	{
	public:
		BigInt();

		BigInt(const std::bitset<N>& b);

		BigInt(const BigInt<N>& b) = default;

		BigInt(unsigned long a);


		~BigInt();

		/// <summary>
		/// �ӷ����������
		/// </summary>
		/// <param name="b">������</param>
		/// <returns>��</returns>
		BigInt<N> operator+(const BigInt<N>& b);

		operator bool();

		/// <summary>
		/// �ӷ������Լ��ۼ�
		/// </summary>
		/// <param name="b">������</param>
		void Add(const BigInt<N>& b);

	private:

		/// <summary>
		/// �ӷ�
		/// </summary>
		/// <param name="a">����</param>
		/// <param name="b">������</param>
		/// <returns>��</returns>
		static BigInt<N> add(BigInt<N> a, BigInt<N> b);
	};



	template<size_t N>
	inline BigInt<N>::BigInt()
	{
	}
	template<size_t N>
	inline BigInt<N>::BigInt(const std::bitset<N>& b): std::bitset<N>(b)
	{
	}
	template<size_t N>
	inline BigInt<N>::BigInt(unsigned long a): std::bitset<N>(a)
	{
		if ((*this)[sizeof(a) * 8 - 1] == 1)
		{
			for (size_t i = this->size()-1; i >= sizeof(a) * 8; i--)
			{
				(*this)[i] = 1;
			}
		}

	}
	template<size_t N>
	inline BigInt<N>::~BigInt()
	{
	}

	template<size_t N>
	inline BigInt<N> BigInt<N>::operator+(const BigInt<N>& b)
	{
		return add(*this, b);
	}

	template<size_t N>
	inline BigInt<N>::operator bool()
	{
		return this->any();
	}

	template<size_t N>
	inline void BigInt<N>::Add(const BigInt<N>& b)
	{
		//TODO:
	}

	template<size_t N>
	inline BigInt<N> BigInt<N>::add(BigInt<N> a, BigInt<N> b)
	{
		BigInt<N> sum = 0;
		BigInt<N> carry = 0;
		while (b)
		{ 
			sum = a ^ b;
			carry = (a & b) << 1;
			a = sum;
			b = carry;
		}
		return sum;
	}
	
	//�ᱬջ
	//template<size_t N>
	//inline BigInt<N> BigInt<N>::add(const BigInt<N>& a, const BigInt<N>& b)
	//{
	//	return b.any() ? add(a ^ b, (a & b) << 1) : a;
	//}

}