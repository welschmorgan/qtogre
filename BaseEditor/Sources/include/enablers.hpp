#ifndef ENABLERS_HPP
# define ENABLERS_HPP
# include <typeinfo>

namespace enable
{
    template<typename T,
             typename TagType>
    class tag
    {
    public:
        typedef TagType tag_type;
        typedef T       tag_subtype;

        tag(const tag_type &_tag = tag_type())
            : mTag(_tag)
        {}
        virtual ~tag()
        {}

        const std::string &getClass() const{ return (typeid(tag_subtype).name()); }

        const tag_type &getTag() const{ return (mTag); }
        void            setTag(const tag_type &tag){ mTag = tag; }

    protected:
        tag_type        mTag;
    };
    template<typename RetType>
    class creator
    {
    public:
        typedef RetType return_type;
        typedef void    arg0_type;

        creator(bool create_now = false)
            : mCreated(false)
        { if (create_now) create(); }

        virtual ~creator()
        { if (mCreated) destroy(); }

        bool        isCreated() const{ return (mCreated); }
        void        setCreated(bool state){ mCreated = state; }

        virtual return_type create(void) = 0;
        virtual void        destroy(void) = 0;
    protected:
        bool        mCreated;
    };
    template<typename RetType, typename A0>
    class creator1
    {
    public:
        typedef RetType return_type;
        typedef A0      arg0_type;

        creator1(bool create_now = false, A0 a0 = A0())
            : mCreated(false)
        { if (create_now) create(a0); }

        virtual ~creator1()
        { if (mCreated) destroy(); }

        bool        isCreated() const{ return (mCreated); }
        void        setCreated(bool state){ mCreated = state; }

        virtual return_type create(A0 a0) = 0;
        virtual void        destroy() = 0;
    protected:
        bool        mCreated;
    };
    template<typename RetType,
             typename A0,
             typename A1>
    class creator2
    {
    public:
        typedef RetType return_type;
        typedef A0      arg0_type;
        typedef A1      arg1_type;

        creator2(bool create_now = false, A0 a0 = A0(), A1 a1 = A1())
            : mCreated(false)
        { if (create_now) create(a0, a1); }

        virtual ~creator2()
        { if (mCreated) destroy(); }

        bool        isCreated() const{ return (mCreated); }
        void        setCreated(bool state){ mCreated = state; }

        virtual return_type create(A0 a0, A1 a1) = 0;
        virtual void        destroy() = 0;
    protected:
        bool        mCreated;
    };
    template<typename RetType,
             typename A0,
             typename A1,
             typename A2>
    class creator3
    {
    public:
        typedef RetType return_type;
        typedef A0      arg0_type;
        typedef A1      arg1_type;

        creator3(bool create_now = false, A0 a0 = A0(), A1 a1 = A1(), A2 a2 = A2())
            : mCreated(false)
        { if (create_now) create(a0, a1, a2); }

        virtual ~creator3()
        { if (mCreated) destroy(); }

        bool        isCreated() const{ return (mCreated); }
        void        setCreated(bool state){ mCreated = state; }

        virtual return_type create(A0 a0, A1 a1, A2 a2) = 0;
        virtual void        destroy() = 0;
    protected:
        bool        mCreated;
    };
}

#endif // ENABLERS_HPP
