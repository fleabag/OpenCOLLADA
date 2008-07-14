/*
    Copyright (c) 2008 NetAllied Systems GmbH

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.
*/


#ifndef __COLLADASTREAMWRITER_INSTANCE_CONTROLLER_H__
#define __COLLADASTREAMWRITER_INSTANCE_CONTROLLER_H__

#include "COLLADAPrerequisites.h"
#include "COLLADAElementWriter.h"
#include "COLLADABindMaterial.h"

#include <string>

namespace COLLADA
{

    /** Class to write an @a \<instance_geometry\> element to the stream*/
    class InstanceController : public ElementWriter
    {

    private:

        /** The material to bind. */
        BindMaterial mBindMaterial;

        /** The URL of the location of the object to instantiate.*/
        String mUrl;

        /** The id of the skeleton data of the controller. */
        String mSkeletonId;

    public:

        /** Constructor
        @param The stream the instance controller should be written to
        */
        InstanceController ( StreamWriter* streamWriter ) 
            : ElementWriter ( streamWriter )
            , mBindMaterial ( streamWriter ) 
            , mUrl ( EMPTY_STRING )
            , mSkeletonId ( EMPTY_STRING )
        {}

        /** Destructor*/
        ~InstanceController(){}

        /** Sets the url of the instance geometry*/
        void setUrl ( const String url )
        {
            mUrl=url;
        }

        /** Returns the url of the instance geometry*/
        const String& getUrl()
        {
            return mUrl;
        }

        BindMaterial& getBindMaterial()
        {
            return mBindMaterial;
        }

        /**
         * Get the id of the skeleton.
         * @return COLLADA::String The skeleton id.
         */
        COLLADA::String getSkeletonId() const { return mSkeletonId; }
        /**
         * Set the skeleton id.
         * @param val Skeleton id to set.
         */
        void setSkeletonId(COLLADA::String val) { mSkeletonId = val; }

        /** Adds the instance geometry to the stream*/
        void add();

    };


} //namespace COLLADA




#endif //__COLLADASTREAMWRITER_INSTANCE_CONTROLLER_H__
