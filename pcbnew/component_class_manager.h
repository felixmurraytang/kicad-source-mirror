/*
 * This program source code file is part of KiCad, a free EDA CAD application.
 *
 * Copyright (C) 2024 KiCad Developers, see AUTHORS.txt for contributors.
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef PCBNEW_COMPONENT_CLASS_MANAGER_H
#define PCBNEW_COMPONENT_CLASS_MANAGER_H

#include <memory>
#include <unordered_map>
#include <unordered_set>
#include <wx/string.h>

#include <board_item.h>

/*
 * A lightweight representation of a component class. The membership within
 * m_consituentClasses allows determination of the type of class this is:
 * 
 * m_constituentClasses.size() == 0: This is a null class (no assigment).
 *     m_name is empty.
 * m_constituentClasses.size() == 1: This is an atomic class. The constituent class
 *     pointer refers to itself. m_name contains the name of the atomic class
 * m_constituentClasses.size() > 1: This is a composite class. The constituent class
 *     pointers refer to all atomic members. m_name contains a comma-delimited list of
 *     all atomic member class names.
 */
class COMPONENT_CLASS
{
public:
    COMPONENT_CLASS( const wxString& name ) : m_name( name ) {}

    /// Fetches the display name of this component class
    wxString GetName() const;

    /// Fetches the full name of this component class
    const wxString& GetFullName() const { return m_name; }

    /// Adds a constituent component class to an effective component class
    void AddConstituentClass( COMPONENT_CLASS* componentClass );

    /// Determines if this (effective) component class contains a specific sub-class
    bool ContainsClassName( const wxString& className ) const;

    /// Determines if this (effective) component class is empty (i.e. no classes defined)
    bool IsEmpty() const;

    /// Fetches a vector of the constituent classes for this (effective) class
    const std::vector<COMPONENT_CLASS*>& GetConstituentClasses() const
    {
        return m_constituentClasses;
    }

private:
    /// The full name of the component class
    wxString m_name;

    /// The COMPONENT_CLASS objects contributing to this complete component class
    std::vector<COMPONENT_CLASS*> m_constituentClasses;
};

class COMPONENT_CLASS_MANAGER
{
public:
    COMPONENT_CLASS_MANAGER();

    /// @brief Gets an effective component class for the given constituent class names
    /// @param classes The names of the constituent component classes
    /// @return Effective COMPONENT_CLASS object
    COMPONENT_CLASS* GetEffectiveComponentClass( std::unordered_set<wxString>& classNames );

    /// Returns the unassigned component class
    const COMPONENT_CLASS* GetNoneComponentClass() const { return m_noneClass.get(); }

protected:
    /// All individual component classes
    std::unordered_map<wxString, std::unique_ptr<COMPONENT_CLASS>> m_classes;

    /// Generated effective component classes
    std::unordered_map<wxString, std::unique_ptr<COMPONENT_CLASS>> m_effectiveClasses;

    /// The class to represent an unassigned component class
    std::unique_ptr<COMPONENT_CLASS> m_noneClass;
};

#endif