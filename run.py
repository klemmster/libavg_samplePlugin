#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Copyright (C) 2013 Archimedes Exhibitions GmbH,
# Saarbrücker Str. 24b, Berlin, Germany
#
# This file contains proprietary source code and confidential
# information. Its contents may not be disclosed or distributed to
# third parties unless prior specific permission by Archimedes
# Exhibitions GmbH, Berlin, Germany is obtained in writing. This applies
# to copies made in any form and using any medium. It applies to
# partial as well as complete copies.

from libavg.app import App
from maindiv import MyMainDiv


if __name__ == "__main__":
    App().run(MyMainDiv())

