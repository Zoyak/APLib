//
//  APBevTreeAnyData.h
//  行为树范型数据
//
//  Created by jl on 15/6/26.
//
//

#ifndef __Zombie3_4__APBevTreeAnyData__
#define __Zombie3_4__APBevTreeAnyData__

#include <stdio.h>

class APBevTreeAnyData
{
public:
    template<typename RealDataType>
    APBevTreeAnyData(RealDataType* data): m_RealData(data)
    {
    }
    
    //获取真实数据类型
    template<typename RealDataType>
    RealDataType& getRealDataType(){
        //D_CHECK(m_RealData);
        return *reinterpret_cast<RealDataType*>(m_RealData);
    }
        
    //获取真实数据类型
    template<typename RealDataType>
    const RealDataType& getRealDataType() const{
        //D_CHECK(m_RealData);
        return *reinterpret_cast<const RealDataType*>(m_RealData);
    }
    

    
    template<typename RealDataType>
    APBevTreeAnyData& operator =(RealDataType* data)
    {
        set<RealDataType>(data);
        return *this;
    }
private:
    
    template<typename RealDataType>
    void set(RealDataType* data)
    {
        m_RealData = reinterpret_cast<void*>(data);
    }
    
private:
    void* m_RealData;
};


#endif /* defined(__Zombie3_4__APBevTreeAnyData__) */
