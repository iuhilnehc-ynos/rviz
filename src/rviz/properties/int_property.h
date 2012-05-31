/*
 * Copyright (c) 2012, Willow Garage, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the Willow Garage, Inc. nor the names of its
 *       contributors may be used to endorse or promote products derived from
 *       this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef INT_PROPERTY_H
#define INT_PROPERTY_H

#include "rviz/properties/property.h"

namespace rviz
{

/** @brief Property specialized to provide max/min enforcement for integers. */
class IntProperty: public Property
{
Q_OBJECT
public:
  IntProperty( const QString& name = QString(),
               int default_value = 0,
               const QString& description = QString(),
               Property* parent = 0,
               const char *changed_slot = 0,
               QObject* receiver = 0 );

  /** @brief Set the new value for this property.  Returns true if the
   * new value is different from the old value, false if same.
   *
   * If the new value is different from the old value, this emits
   * aboutToChange() before changing the value and changed() after.
   *
   * Overridden from Property::setValue() to enforce minimum and maximum. */
  virtual bool setValue( const QVariant& new_value );
  
  virtual int getInt() const { return getValue().toInt(); }

  void setMin( int min );
  int getMin() { return min_; }
  void setMax( int max );
  int getMax() { return max_; }

  virtual QWidget* createEditor( QWidget* parent,
                                 const QStyleOptionViewItem& option,
                                 const QModelIndex& index );

public Q_SLOTS:
  void setInt( int new_value ) { setValue( new_value ); }

private:
  int min_;
  int max_;
};

} // end namespace rviz

#endif // INT_PROPERTY_H