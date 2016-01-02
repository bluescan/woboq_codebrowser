/****************************************************************************
 * Copyright (C) 2012-2016 Woboq GmbH
 * Olivier Goffart <contact at woboq.com>
 * http://woboq.com/codebrowser.html
 *
 * This file is part of the Woboq Code Browser.
 *
 * Commercial License Usage:
 * Licensees holding valid commercial licenses provided by Woboq may use
 * this file in accordance with the terms contained in a written agreement
 * between the licensee and Woboq.
 * For further information see http://woboq.com/codebrowser.html
 *
 * Alternatively, this work may be used under a Creative Commons
 * Attribution-NonCommercial-ShareAlike 3.0 (CC-BY-NC-SA 3.0) License.
 * http://creativecommons.org/licenses/by-nc-sa/3.0/deed.en_US
 * This license does not allow you to use the code browser to assist the
 * development of your commercial software. If you intent to do so, consider
 * purchasing a commercial licence.
 ****************************************************************************/

#pragma once

#include <memory>

// clang 3.6 uses unique_ptr in many places that was not using it before
template<typename T> struct MaybeUnique {
    T *val;
    operator T*() { return val; }
    template <typename X> operator std::unique_ptr<X> () && {  return std::unique_ptr<X>(val); }
};
template<typename T> MaybeUnique<T> maybe_unique(T* val) { return {val}; }

