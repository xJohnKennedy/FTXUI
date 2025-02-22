#include <ftxui/dom/elements.hpp>  // for text, operator|, dim, Fit, hbox, Element
#include <ftxui/screen/screen.hpp>  // for Full, Screen
#include <memory>                   // for allocator

#include "ftxui/dom/flexbox_config.hpp"  // for ftxui
#include "ftxui/dom/node.hpp"            // for Render

int main(int argc, const char* argv[]) {
  using namespace ftxui;
  auto document =  //
      hbox({
          text("This text is "),
          text("dim") | dim,
          text(". Do you like it?"),
      });
  auto screen = Screen::Create(Dimension::Full(), Dimension::Fit(document));
  Render(screen, document);
  screen.Print();

  return 0;
}

// Copyright 2020 Arthur Sonzogni. All rights reserved.
// Use of this source code is governed by the MIT license that can be found in
// the LICENSE file.
